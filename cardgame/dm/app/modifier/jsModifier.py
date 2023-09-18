import re

# index.jsのデータ部分を書き換える
def modifyIndexJsData(outFilePath, count, jpnNameAggregatedData):
    # ファイルを読み込む
    with open(outFilePath, encoding='utf-8') as js:
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
    with open(outFilePath, mode='w', encoding='utf-8') as js:
        js.write(newContent)