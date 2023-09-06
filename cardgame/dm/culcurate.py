import csv
import re


# カラムのindex定義
DECK1_COL_NO = 1
DECK2_COL_NO = 2
WIN_COL_NO = 3

# 戦績集計データ
count = 0
aggregatedData = {}

# 戦績データを更新する
def updateAggregatedData(winnerCol, loserCol):
    aggregatedData[row[winnerCol]]['wins'] += 1
    aggregatedData[row[winnerCol]]['wp'] = aggregatedData[row[winnerCol]]['wins'] / (aggregatedData[row[winnerCol]]['wins'] + aggregatedData[row[winnerCol]]['loses'])

    aggregatedData[row[loserCol]]['loses'] += 1
    aggregatedData[row[loserCol]]['wp'] = aggregatedData[row[loserCol]]['wins'] / (aggregatedData[row[loserCol]]['wins'] + aggregatedData[row[loserCol]]['loses'])


def getJpnDeckName(name):
    if name == 'bs':
        return 'ビクトリー・ソウル'
    elif name == 'hdm':
        return 'ヘヴィ・デス・メタル'
    elif name == 'neh':
        return 'ネバー・エンディング・ヒーロー'
    elif name == 'ymt':
        return 'BATTLE of YAMATO魂'
    elif name == 'ngt':
        return 'Arcadias騎士団'
    else:
        return 'Undefined'


def getJpnNameAggregatedData():
    tmpAggregatedData = {}
    for key in aggregatedData:
        newKey = getJpnDeckName(key)
        tmpAggregatedData[newKey] = aggregatedData[key]
    
    return tmpAggregatedData


# index.jsのデータ部分を書き換える
def modifyIndexJsData():
    # ファイルを読み込む
    with open('./src/index.js', encoding='utf-8') as js:
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
    with open('./src/index.js', mode='w', encoding='utf-8') as js:
        js.write(newContent)


# csvファイルを読み込む
with open('data/results.csv') as f:
    reader = csv.reader(f)
    # 1行目はヘッダ行なので読み込まない
    rows = [row for row in reader]
    for row in rows[1:]:
        # 集計対象のデッキが戦績集計データ内に存在しなければ初期化
        if row[DECK1_COL_NO] not in aggregatedData:
            aggregatedData[row[DECK1_COL_NO]] = {'wins': 0, 'loses': 0, 'wp': 0}
        if row[DECK2_COL_NO] not in aggregatedData:
            aggregatedData[row[DECK2_COL_NO]] = {'wins': 0, 'loses': 0, 'wp': 0}
        
        if row[WIN_COL_NO] == row[DECK1_COL_NO]:
            updateAggregatedData(DECK1_COL_NO, DECK2_COL_NO)
        else:
            updateAggregatedData(DECK2_COL_NO, DECK1_COL_NO)
        
        # 対戦回数を加算
        count += 1

    modifyIndexJsData()