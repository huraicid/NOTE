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
