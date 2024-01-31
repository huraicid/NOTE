#pragma once

#include <vector>
#include "Edge.h"

// グラフを表すにはstd::vectorで十分である
using Graph = std::vector<std::vector<Edge>>;

namespace GraphUtil {
	// 定数一覧
	const int INF_DIST = 9999999;

	// グラフの中身を表示
	void printAdjacencyList(Graph graph);

	// 幅優先探索をして始点からの最短経路長の配列を返す
	std::vector<int> breadthFirstSearch(const Graph& graph, int start);

	// 深さ優先探索
	bool depthFirstSearch(const Graph& graph, int start, int goal, std::vector<bool> seenVetrexes = std::vector<bool>(0));
}
