# pycacheファイルを出力しないようにする
import sys
sys.dont_write_bytecode = True

# 外部モジュール読み込み
import reader.dataReader as dataReader
import converter.dataConverter as dataConverter
import modifier.jsModifier as jsModifier

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

    # jsファイルを書き換える
    jsModifier.modifyIndexJsData(JS_OUT_PATH, count, jpnNameAggregatedData)


if __name__ == '__main__':
    main()