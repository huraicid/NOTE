import csv
import math
import re

# 読み込むCSVファイルの相対パス
CSV_SOURCE_PATH = './../data/results.csv'
# 書き換え先jsの相対ファイルパス
JS_OUT_PATH = './../src/index.js'

# カラムのindex定義
DECK1_COL_NO = 1
DECK2_COL_NO = 2
WIN_COL_NO = 3

# 戦績集計データ
count = 0
aggregatedData = {}

# main部
def main():
    readResultData()
    modifyIndexJsData()

# csvファイルから戦績データを読み込み集計データを作成する
def readResultData():
    with open(CSV_SOURCE_PATH) as f:
        # csvファイルを読み込む
        reader = csv.reader(f)
        rows = [row for row in reader]

        # 対戦回数（データ数）を計算
        # ヘッダ行を除いた行数
        global count
        count = len(rows) - 1

        # 1行目はヘッダ行なので読み込まない
        for row in rows[1:]:
            # 集計対象のデッキが戦績集計データ内に存在しなければ初期化
            if row[DECK1_COL_NO] not in aggregatedData:
                aggregatedData[row[DECK1_COL_NO]] = {'wins': 0, 'loses': 0, 'wp': 0}
            if row[DECK2_COL_NO] not in aggregatedData:
                aggregatedData[row[DECK2_COL_NO]] = {'wins': 0, 'loses': 0, 'wp': 0}
            
            # 勝ち負けデータを読み込み更新する
            if row[WIN_COL_NO] == row[DECK1_COL_NO]:
                updateAggregatedData(row, DECK1_COL_NO, DECK2_COL_NO)
            else:
                updateAggregatedData(row, DECK2_COL_NO, DECK1_COL_NO)

# 戦績データを更新する
def updateAggregatedData(row, winnerCol, loserCol):
    aggregatedData[row[winnerCol]]['wins'] += 1
    winnerWpNotRounded = aggregatedData[row[winnerCol]]['wins'] / (aggregatedData[row[winnerCol]]['wins'] + aggregatedData[row[winnerCol]]['loses'])
    aggregatedData[row[winnerCol]]['wp'] = math.floor(winnerWpNotRounded * 10 ** 2) / (10 ** 2)

    aggregatedData[row[loserCol]]['loses'] += 1
    loserWpNotRounded = aggregatedData[row[loserCol]]['wins'] / (aggregatedData[row[loserCol]]['wins'] + aggregatedData[row[loserCol]]['loses'])
    aggregatedData[row[loserCol]]['wp'] = math.floor(loserWpNotRounded * 10 ** 2) / (10 ** 2)

# index.jsのデータ部分を書き換える
def modifyIndexJsData():
    # ファイルを読み込む
    with open(JS_OUT_PATH, encoding='utf-8') as js:
        content = js.read()
    
    # 差し替え用データを作成
    # 対戦回数部
    newCountElem = 'COUNT = ' + str(count)
    newContent = re.sub('COUNT = \d+', newCountElem, content)

    # 行データ部
    jpnNameaggregatedData = getJpnNameAggregatedData()
    newData = '['
    for key in jpnNameaggregatedData:
        row = jpnNameaggregatedData[key]
        rowData = '\"{}\", \"{}\", \"{}\", \"{}\"'.format(key, row['wins'], row['loses'], row['wp'])
        newData += ('[' + rowData + ']' + ',')
    newData = newData[:-1] + ']'
    newContent = re.sub('\[\[.*\]\]', newData, newContent)

    # ファイルの書き換え
    with open(JS_OUT_PATH, mode='w', encoding='utf-8') as js:
        js.write(newContent)

# 戦績集計データのデッキ名部分を略称から日本語の正式名称に修正したものを取得する
def getJpnNameAggregatedData():
    tmpAggregatedData = {}
    for key in aggregatedData:
        newKey = getJpnDeckName(key)
        tmpAggregatedData[newKey] = aggregatedData[key]
    
    return tmpAggregatedData

# デッキ名の略称を日本語の正式名称に変換する
def getJpnDeckName(name):
    if name == 'bs':
        return 'DMC-39 ビクトリー・ソウル'
    elif name == 'hdm':
        return 'DMC-40 ヘヴィ・デス・メタル'
    elif name == 'neh':
        return 'DMC-43 ネバー・エンディング・ヒーロー'
    elif name == 'ymt':
        return 'DMC-45 BATTLE of YAMATO魂'
    elif name == 'ngt':
        return 'DMC-46 Arcadias騎士団'
    else:
        return 'Undefined'


if __name__ == '__main__':
    main()