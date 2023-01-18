#pragma once

#include <vector>
#include "Edge.h"

// �O���t��\���ɂ�std::vector�ŏ\���ł���
using Graph = std::vector<std::vector<Edge>>;

namespace GraphUtil {
	void printAdjacencyList(Graph graph);
}
