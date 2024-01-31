#include "Edge.h"
#include "Graph.h"
#include <vector>  
#include <iostream>

int main() {
	// ���_���ƕӐ�
	int N, M;
	std::cin >> N >> M;

	// �O���t�̏�����
	Graph G(N);
	for (int i = 0; i < M; i++) {
		// �n�_
		int from;

		// �s��
		int to;

		// �d��
		long long w;

		// ���͂��󂯕t���ĕӃC���X�^���X���쐬���i�[
		std::cin >> from >> to >> w;
		G[from].push_back(Edge(to, w));
	}

	// �O���t�̒��g��\��
	GraphUtil::printAdjacencyList(G);

	// ���D��T��
	int start = 1;
	std::vector<int> minDists1 = GraphUtil::breadthFirstSearch(G, start);
	std::cout << "���D��T��: " << std::endl;
	for (int i = 0; i < minDists1.size(); i++) {
		int dist = minDists1[i];

		if (start == i) {
			continue;
		}

		std::cout << start << " -> " << i << ": ";
		if (dist < 0) {
			std::cout << "unreachable" << std::endl;
		}
		else {
			std::cout << dist << std::endl;
		}
	}

	// �[���D��T����start����goal�֓��B�\�����肷��
	std::cout << "�[���D��T��: " << std::endl;
	start = 0;
	int goal = 2;
	std::cout << start << " -> " << goal << ": ";
	if (GraphUtil::depthFirstSearch(G, start, goal)) {
		std::cout << "reachable!" << std::endl;
	}
	else {
		std::cout << "unreachable" << std::endl;
	}
	
	return 0;
}
