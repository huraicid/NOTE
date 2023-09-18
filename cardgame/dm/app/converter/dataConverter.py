def getJpnNameAggregatedData(aggregatedData):
    """
    戦績集計データのデッキ名部分を、
    日本語の正式名称に修正したものを取得する。

    Args:
        aggregatedData (dictonary): 戦績データ

    Returns:
        dictorany: デッキ名を日本語名に変換した戦績データ
    """

    tmpAggregatedData = {}
    for key in aggregatedData:
        newKey = getJpnDeckName(key)
        tmpAggregatedData[newKey] = aggregatedData[key]

    return tmpAggregatedData


def getJpnDeckName(abb):
    """
    デッキ名の略称を日本語の正式名称に変換したものを取得する。

    Args:
        name (string): 略称名
    Returns:
        string: 返還後の日本語正式名称
    """

    # NOTE: pythonはswitch文がないのでこの書き方でやるしかない
    if abb == 'bs':
        return 'DMC-39 ビクトリー・ソウル'
    elif abb == 'hdm':
        return 'DMC-40 ヘヴィ・デス・メタル'
    elif abb == 'neh':
        return 'DMC-43 ネバー・エンディング・ヒーロー'
    elif abb == 'ymt':
        return 'DMC-45 BATTLE of YAMATO魂'
    elif abb == 'ngt':
        return 'DMC-46 Arcadias騎士団'
    else:
        return 'Undefined'
