#pragma once

#include <vector>
#include "Edge.h"

// グラフを表すにはstd::vectorで十分である
using Graph = std::vector<std::vector<Edge>>;

namespace GraphUtil {
	void printAdjacencyList(Graph graph);
}
