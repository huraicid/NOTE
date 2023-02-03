import graphviz

# Graphvizのオブジェクトを作成 --- (*1)
g = graphviz.Digraph(format='png')
g.attr('graph', rankdir='LR')

# テストデータファイル読み込み
with open('testData.txt', 'r', encoding='UTF-8') as f:
    for line in f:
        targetData = line.split(' ')
        # データ部のフォーマットにあっていない行は読み飛ばす
        if len(targetData) != 3:
            continue
        # ノード、辺を追加
        g.node(targetData[0])
        g.edge(targetData[0], targetData[1], label=targetData[2].strip())

# ファイル出力
g.render('testData')