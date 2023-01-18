#pragma once

#include <vector>
#include "Edge.h"

// �O���t��\���ɂ�std::vector�ŏ\���ł���
using Graph = std::vector<std::vector<Edge>>;

namespace GraphUtil {
	// �O���t�̒��g��\��
	void printAdjacencyList(Graph graph);

	// ���D��T��
	void breadthFirstSearch(const Graph& graph, int start);
}
