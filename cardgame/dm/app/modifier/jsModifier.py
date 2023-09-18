import re

def modifyIndexJsData(outJsPath, count, displayAggregatedData):
    """
    対象のjsファイルを引数の戦績データで書き換える。

    Args:
        outJsPath (string): 書き換え先のjsファイル
        count (int): 対戦回数
        displayAggregatedData (dictionary): 表示用戦績データ
    """

    # ファイルを読み込む
    with open(outJsPath, encoding='utf-8') as js:
        content = js.read()

    # 差し替え用データを作成
    # 対戦回数部
    newCountElem = 'COUNT = ' + str(count)
    newContent = re.sub('COUNT = \d+', newCountElem, content)

    # 行データ部
    newData = '['
    for key in displayAggregatedData:
        row = displayAggregatedData[key]
        rowData = '\"{}\", \"{}\", \"{}\", \"{}\"'.format(key, row['wins'], row['loses'], row['wp'])
        newData += ('[' + rowData + ']' + ',')
    newData = newData[:-1] + ']'
    newContent = re.sub('\[\[.*\]\]', newData, newContent)

    # ファイルの書き換え
    with open(outJsPath, mode='w', encoding='utf-8') as js:
        js.write(newContent)