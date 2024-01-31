#pragma once

#include <vector>
#include "Edge.h"

// �O���t��\���ɂ�std::vector�ŏ\���ł���
using Graph = std::vector<std::vector<Edge>>;

namespace GraphUtil {
	// �萔�ꗗ
	const int INF_DIST = 9999999;

	// �O���t�̒��g��\��
	void printAdjacencyList(Graph graph);

	// ���D��T�������Ďn�_����̍ŒZ�o�H���̔z���Ԃ�
	std::vector<int> breadthFirstSearch(const Graph& graph, int start);

	// �[���D��T��
	bool depthFirstSearch(const Graph& graph, int start, int goal, std::vector<bool> seenVetrexes = std::vector<bool>(0));
}
