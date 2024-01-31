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
/// グラフgraphにおいて、頂点startを始点とした幅優先探索を行い、<br>
/// startからの最短経路長の配列を返します。
/// </summary>
/// <param name="graph">グラフ</param>
/// <param name="start">始点の頂点番号</param>
/// <return>最短経路長の配列</return>
std::vector<int>  GraphUtil::breadthFirstSearch(const Graph& graph, int start) {
	// 各頂点のstartからの最短経路長
	// -1は未訪問を表す
	std::vector<int> minDists(graph.size(), -1);

	// 訪問予定の頂点（キュー構造）
	std::queue<int> todoVertexes;

	// 初期条件
	// 始点startは最短経路長を0とし、訪問予定の頂点をstartのみにする
	minDists[start] = 0;
	todoVertexes.push(start);

	// 訪問予定の頂点が空になるまで探索が続けられる
	while (!todoVertexes.empty()) {
		// 訪問先の頂点を取得する
		int v = todoVertexes.front();
		todoVertexes.pop();

		// toからたどれる頂点をすべて探索予定に追加する
		for (Edge x : graph[v]) {
			// すでに探索済みの頂点は飛ばす
			if (minDists[x.to] != -1) {
				continue;
			}

			// 未訪問の頂点を訪問予定に追加する
			todoVertexes.push(x.to);
			minDists[x.to] = minDists[v] + x.w;
		}
	}

	return minDists;
}

/// <summary>
/// グラフgraphにおいて、頂点startを始点から終点へ到達可能であるかを、<br>
/// 深さ優先探索を用いて判定する。
/// </summary>
/// <param name="graph">グラフ</param>
/// <param name="start">始点の頂点番号</param>
/// <param name="minDists">最短経路長の配列（省略可）</param>
bool GraphUtil::depthFirstSearch(const Graph& graph, int start, int goal, std::vector<bool> seenVetrexes) {
	// 最初の呼び出しを行ったとき、各頂点の訪問済みフラグを初期化する
	if (seenVetrexes.size() < 1) {
		seenVetrexes = std::vector<bool>(graph.size(), false);
		seenVetrexes[start] = true;
	}

	// startから行ける各頂点について再帰的に探索を行う
	for (Edge nextEdge : graph[start]) {
		// 探索済みであればスキップする
		if (seenVetrexes[nextEdge.to]) {
			continue;
		}

		// 探索済みフラグを立てる
		seenVetrexes[nextEdge.to] = true;

		// 終点へ到達した場合は到達可能である判定を返す
		if (seenVetrexes[goal]) {
			return true;
		}

		// 再帰実行
		return depthFirstSearch(graph, nextEdge.to, goal, seenVetrexes);
	}

	return false;
}