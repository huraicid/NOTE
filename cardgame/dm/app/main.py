import reader.dataReader as dataReader
import re

# 読み込むCSVファイルの相対パス
CSV_SOURCE_PATH = './../data/results.csv'
# 書き換え先jsの相対ファイルパス
JS_OUT_PATH = './../src/index.js'


# main部
def main():
    count, aggregatedData = dataReader.readResultData(CSV_SOURCE_PATH)
    modifyIndexJsData(count, aggregatedData)


# index.jsのデータ部分を書き換える
def modifyIndexJsData(count, aggregatedData):
    # ファイルを読み込む
    with open(JS_OUT_PATH, encoding='utf-8') as js:
        content = js.read()
    
    # 差し替え用データを作成
    # 対戦回数部
    newCountElem = 'COUNT = ' + str(count)
    newContent = re.sub('COUNT = \d+', newCountElem, content)

    # 行データ部
    jpnNameaggregatedData = getJpnNameAggregatedData(aggregatedData)
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
def getJpnNameAggregatedData(aggregatedData):
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