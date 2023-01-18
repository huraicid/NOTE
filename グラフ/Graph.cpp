#include <vector>  
#include <iostream>

/// <summary>
/// 辺クラス
/// </summary>
class Edge {
public: 
	// 行先の頂点番号
	int to;

	// 重み
	long long w;

	// コンストラクタ
	Edge(int to, long long w) : to(to), w(w) {};
};

// グラフを表すにはstd::vectorで十分である
using Graph = std::vector<std::vector<Edge>>;

// プロトタイプ宣言
void printAdjacencyList(Graph graph);

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

	printAdjacencyList(G);
	
	return 0;
}

/// <summary>
/// 引数のグラフの各頂点からの行き先を表示します。
/// </summary>
/// <param name="graph">グラフ</param>
void printAdjacencyList(Graph graph) {
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

void search(const Graph& G, int s) {

}
