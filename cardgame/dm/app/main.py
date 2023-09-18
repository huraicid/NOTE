import reader.dataReader as dataReader
import converter.dataConverter as dataConverter
import re

# 読み込むCSVファイルの相対パス
CSV_SOURCE_PATH = './../data/results.csv'
# 書き換え先jsの相対ファイルパス
JS_OUT_PATH = './../src/index.js'


# main部
def main():
    # csvファイルを読み込む
    count, aggregatedData = dataReader.readResultData(CSV_SOURCE_PATH)

    # 表示用にデータを変換
    jpnNameAggregatedData = dataConverter.getJpnNameAggregatedData(aggregatedData)
    modifyIndexJsData(count, jpnNameAggregatedData)


# index.jsのデータ部分を書き換える
def modifyIndexJsData(count, jpnNameAggregatedData):
    # ファイルを読み込む
    with open(JS_OUT_PATH, encoding='utf-8') as js:
        content = js.read()
    
    # 差し替え用データを作成
    # 対戦回数部
    newCountElem = 'COUNT = ' + str(count)
    newContent = re.sub('COUNT = \d+', newCountElem, content)

    # 行データ部
    newData = '['
    for key in jpnNameAggregatedData:
        row = jpnNameAggregatedData[key]
        rowData = '\"{}\", \"{}\", \"{}\", \"{}\"'.format(key, row['wins'], row['loses'], row['wp'])
        newData += ('[' + rowData + ']' + ',')
    newData = newData[:-1] + ']'
    newContent = re.sub('\[\[.*\]\]', newData, newContent)

    # ファイルの書き換え
    with open(JS_OUT_PATH, mode='w', encoding='utf-8') as js:
        js.write(newContent)

if __name__ == '__main__':
    main()