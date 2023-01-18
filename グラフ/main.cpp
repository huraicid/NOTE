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
	for (int i = 0; i < N; i++) {
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
	GraphUtil::breadthFirstSearch(G, 0);
	
	return 0;
}
