#include "Graph.h"
#include <iostream>

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