import csv
import math

# カラムのindex定義
# NOTE: pythonは定数を定義する修飾子が無いらしい
DECK1_COL_NO = 1
DECK2_COL_NO = 2
WIN_COL_NO = 3

# csvファイルから戦績データを読み込み集計データを作成する
def readResultData(csvSourcePath):
    """
    csvファイルから戦績データを読み込み、集計データを作成する。

    Args:
        csvSourcePath (string): 読み込むcsvファイルのファイルパス

    Returns:
        int: 対戦回数
        dictionary: 戦績データ
    """
    # 戻り値用データ
    count = 0
    aggregatedData = {}

    with open(csvSourcePath) as f:
        # csvファイルを読み込む
        reader = csv.reader(f)
        rows = [row for row in reader]

        # 対戦回数（データ数）を計算
        # ヘッダ行を除いた行数
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
                aggregatedData = updateAggregatedData(row, aggregatedData, DECK1_COL_NO, DECK2_COL_NO)
            else:
                aggregatedData = updateAggregatedData(row, aggregatedData, DECK2_COL_NO, DECK1_COL_NO)

    return count, aggregatedData


def updateAggregatedData(row, aggregatedData, winnerCol, loserCol):
    """
    戦績データを更新し、更新データを取得する

    Args:
        row (array): 行データ
        aggregatedData (dictonary): 更新元戦績データ
        winnerCol (int): 勝者側の配列のindex
        loserCol (int): 敗者側の配列のindex

    Returns:
        _type_: 更新した戦績データ
    """

    aggregatedData[row[winnerCol]]['wins'] += 1
    winnerWpNotRounded = aggregatedData[row[winnerCol]]['wins'] / (aggregatedData[row[winnerCol]]['wins'] + aggregatedData[row[winnerCol]]['loses'])
    aggregatedData[row[winnerCol]]['wp'] = math.floor(winnerWpNotRounded * 10 ** 2) / (10 ** 2)

    aggregatedData[row[loserCol]]['loses'] += 1
    loserWpNotRounded = aggregatedData[row[loserCol]]['wins'] / (aggregatedData[row[loserCol]]['wins'] + aggregatedData[row[loserCol]]['loses'])
    aggregatedData[row[loserCol]]['wp'] = math.floor(loserWpNotRounded * 10 ** 2) / (10 ** 2)

    return aggregatedData