#include "Graph.h"
#include <iostream>
#include <queue>

/// <summary>
/// �����̃O���t�̊e���_����̍s�����\�����܂��B
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
/// <param name="graph">�O���t</param>
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
/// �O���tgraph�ɂ����āA���_start���n�_�Ƃ������D��T�����s���B
/// </summary>
/// <param name="graph">�O���t</param>
/// <param name="start">�n�_�̒��_</param>
void GraphUtil::breadthFirstSearch(const Graph& graph, int start) {
	// �e���_�̖K��ς݃t���O
	std::vector<bool> seenVertexes(graph.size(), false);

	// �K��\��̒��_�i�L���[�\���j
	std::queue<int> todoVertexes;

	// ��������
	// �n�_start�͒T���ς݂Ƃ��A�K��\��̒��_��start�݂̂ɂ���
	seenVertexes[start] = true;
	todoVertexes.push(start);

	// �K��\��̒��_����ɂȂ�܂ŒT������������
	while (!todoVertexes.empty()) {
		// �K���̒��_���擾����
		int v = todoVertexes.front();
		todoVertexes.pop();

		// to���炽�ǂ�钸�_�����ׂĒT���\��ɒǉ�����
		for (Edge x : graph[v]) {
			// ���łɒT���ς݂̒��_�͔�΂�
			if (seenVertexes[v]) {
				continue;
			}

			// ���K��̒��_��K��\��ɒǉ�����
			todoVertexes.push(x.to);
			seenVertexes[x.to] = true;
		}
	}
}