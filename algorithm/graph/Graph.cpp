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
/// �O���tgraph�ɂ����āA���_start���n�_�Ƃ������D��T�����s���A<br>
/// start����̍ŒZ�o�H���̔z���Ԃ��܂��B
/// </summary>
/// <param name="graph">�O���t</param>
/// <param name="start">�n�_�̒��_�ԍ�</param>
/// <return>�ŒZ�o�H���̔z��</return>
std::vector<int>  GraphUtil::breadthFirstSearch(const Graph& graph, int start) {
	// �e���_��start����̍ŒZ�o�H��
	// -1�͖��K���\��
	std::vector<int> minDists(graph.size(), -1);

	// �K��\��̒��_�i�L���[�\���j
	std::queue<int> todoVertexes;

	// ��������
	// �n�_start�͍ŒZ�o�H����0�Ƃ��A�K��\��̒��_��start�݂̂ɂ���
	minDists[start] = 0;
	todoVertexes.push(start);

	// �K��\��̒��_����ɂȂ�܂ŒT������������
	while (!todoVertexes.empty()) {
		// �K���̒��_���擾����
		int v = todoVertexes.front();
		todoVertexes.pop();

		// to���炽�ǂ�钸�_�����ׂĒT���\��ɒǉ�����
		for (Edge x : graph[v]) {
			// ���łɒT���ς݂̒��_�͔�΂�
			if (minDists[x.to] != -1) {
				continue;
			}

			// ���K��̒��_��K��\��ɒǉ�����
			todoVertexes.push(x.to);
			minDists[x.to] = minDists[v] + x.w;
		}
	}

	return minDists;
}

/// <summary>
/// �O���tgraph�ɂ����āA���_start���n�_����I�_�֓��B�\�ł��邩���A<br>
/// �[���D��T����p���Ĕ��肷��B
/// </summary>
/// <param name="graph">�O���t</param>
/// <param name="start">�n�_�̒��_�ԍ�</param>
/// <param name="minDists">�ŒZ�o�H���̔z��i�ȗ��j</param>
bool GraphUtil::depthFirstSearch(const Graph& graph, int start, int goal, std::vector<bool> seenVetrexes) {
	// �ŏ��̌Ăяo�����s�����Ƃ��A�e���_�̖K��ς݃t���O������������
	if (seenVetrexes.size() < 1) {
		seenVetrexes = std::vector<bool>(graph.size(), false);
		seenVetrexes[start] = true;
	}

	// start����s����e���_�ɂ��čċA�I�ɒT�����s��
	for (Edge nextEdge : graph[start]) {
		// �T���ς݂ł���΃X�L�b�v����
		if (seenVetrexes[nextEdge.to]) {
			continue;
		}

		// �T���ς݃t���O�𗧂Ă�
		seenVetrexes[nextEdge.to] = true;

		// �I�_�֓��B�����ꍇ�͓��B�\�ł��锻���Ԃ�
		if (seenVetrexes[goal]) {
			return true;
		}

		// �ċA���s
		return depthFirstSearch(graph, nextEdge.to, goal, seenVetrexes);
	}

	return false;
}