#include "Edge.h"
#include "Graph.h"
#include <vector>  
#include <iostream>

int main() {
	// Έ_ΖΣ
	int N, M;
	std::cin >> N >> M;

	// OtΜϊ»
	Graph G(N);
	for (int i = 0; i < M; i++) {
		// n_
		int from;

		// sζ
		int to;

		// dέ
		long long w;

		// όΝπσ―t―ΔΣCX^Xπμ¬΅i[
		std::cin >> from >> to >> w;
		G[from].push_back(Edge(to, w));
	}

	// OtΜgπ\¦
	GraphUtil::printAdjacencyList(G);

	// DζTυ
	int start = 1;
	std::vector<int> minDists1 = GraphUtil::breadthFirstSearch(G, start);
	std::cout << "DζTυ: " << std::endl;
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

	// [³DζTυΕstart©ηgoalΦBΒ\©»θ·ι
	std::cout << "[³DζTυ: " << std::endl;
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
