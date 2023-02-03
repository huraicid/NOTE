import graphviz

# テストデータファイル読み込み
f = open('testData.txt', 'r', encoding='UTF-8')

# Graphvizのオブジェクトを作成 --- (*1)
g = graphviz.Digraph(format='png', filename='test')

# ノードを3つ作成 --- (*2)
g.node('0')
g.node('1')
g.node('2')
g.node('3')
g.node('4')
g.node('5')
g.node('6')
g.node('7')

# ノードを接続する --- (*3)
g.edge('0', '5')
g.edge('1', '3')
g.edge('1', '4')
g.edge('1', '6')
g.edge('2', '5')
g.edge('2', '7')
g.edge('3', '0')
g.edge('3', '7')
g.edge('4', '2')
g.edge('4', '6')
g.edge('6', '7')
g.edge('7', '0')

# ファイル出力
g.render('testData')