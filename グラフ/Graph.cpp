#include "Graph.h"
#include <iostream>
#include <queue>

/// <summary>
/// 引数のグラフの各頂点からの行き先を表示します。
/// </summary>
/// <example>
/// <code>
/// 5 10
/// 4 1 0
/// 4 2 0
/// 4 6 0
/// 1 3 0
/// 1 6 0
/// G[0] = {}
/// G[1] = { 3, 6 }
/// G[2] = {}
/// G[3] = {}
/// G[4] = { 1, 2, 6 }
/// </code>
/// </example>
/// <param name="graph">グラフ</param>
void GraphUtil::printAdjacencyList(Graph graph) {
	for (int i = 0; i < graph.size(); i++) {
		std::cout << "G[" << i << "] = {";

		for (int j = 0; j < graph[i].size(); j++) {
			std::cout << graph[i][j].to;

			if (j < graph[i].size() - 1) {
				std::cout << ", ";
			}
		}

		std::cout << "}" << std::endl;
	}
}

/// <summary>
/// グラフgraphにおいて、頂点startを始点とした幅優先探索を行う。
/// </summary>
/// <param name="graph">グラフ</param>
/// <param name="start">始点の頂点</param>
void GraphUtil::breadthFirstSearch(const Graph& graph, int start) {
	// 各頂点の訪問済みフラグ
	std::vector<bool> seenVertexes(graph.size(), false);

	// 訪問予定の頂点（キュー構造）
	std::queue<int> todoVertexes;

	// 初期条件
	// 始点startは探索済みとし、訪問予定の頂点をstartのみにする
	seenVertexes[start] = true;
	todoVertexes.push(start);

	// 訪問予定の頂点が空になるまで探索が続けられる
	while (!todoVertexes.empty()) {
		// 訪問先の頂点を取得する
		int v = todoVertexes.front();
		todoVertexes.pop();

		// toからたどれる頂点をすべて探索予定に追加する
		for (Edge x : graph[v]) {
			// すでに探索済みの頂点は飛ばす
			if (seenVertexes[v]) {
				continue;
			}

			// 未訪問の頂点を訪問予定に追加する
			todoVertexes.push(x.to);
			seenVertexes[x.to] = true;
		}
	}
}