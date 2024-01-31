#include "Edge.h"
#include "Graph.h"
#include <vector>  
#include <iostream>

int main() {
	// ’¸“_”‚Æ•Ó”
	int N, M;
	std::cin >> N >> M;

	// ƒOƒ‰ƒt‚Ì‰Šú‰»
	Graph G(N);
	for (int i = 0; i < M; i++) {
		// n“_
		int from;

		// sæ
		int to;

		// d‚İ
		long long w;

		// “ü—Í‚ğó‚¯•t‚¯‚Ä•ÓƒCƒ“ƒXƒ^ƒ“ƒX‚ğì¬‚µŠi”[
		std::cin >> from >> to >> w;
		G[from].push_back(Edge(to, w));
	}

	// ƒOƒ‰ƒt‚Ì’†g‚ğ•\¦
	GraphUtil::printAdjacencyList(G);

	// •—Dæ’Tõ
	int start = 1;
	std::vector<int> minDists1 = GraphUtil::breadthFirstSearch(G, start);
	std::cout << "•—Dæ’Tõ: " << std::endl;
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

	// [‚³—Dæ’Tõ‚Åstart‚©‚çgoal‚Ö“’B‰Â”\‚©”»’è‚·‚é
	std::cout << "[‚³—Dæ’Tõ: " << std::endl;
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
