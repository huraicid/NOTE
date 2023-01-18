#pragma once

#include <vector>
#include "Edge.h"

// グラフを表すにはstd::vectorで十分である
using Graph = std::vector<std::vector<Edge>>;

namespace GraphUtil {
	// グラフの中身を表示
	void printAdjacencyList(Graph graph);

	// 幅優先探索
	void breadthFirstSearch(const Graph& graph, int start);
}
