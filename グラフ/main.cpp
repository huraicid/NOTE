#include "Edge.h"
#include "Graph.h"
#include <vector>  
#include <iostream>

int main() {
	// 頂点数と辺数
	int N, M;
	std::cin >> N >> M;

	// グラフの初期化
	Graph G(N);
	for (int i = 0; i < N; i++) {
		// 始点
		int from;

		// 行先
		int to;

		// 重み
		long long w;

		// 入力を受け付けて辺インスタンスを作成し格納
		std::cin >> from >> to >> w;
		G[from].push_back(Edge(to, w));
	}

	// グラフの中身を表示
	GraphUtil::printAdjacencyList(G);

	// 幅優先探索
	GraphUtil::breadthFirstSearch(G, 0);
	
	return 0;
}
