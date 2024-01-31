/**
 * ダイクストラ法のアルゴリズム。
 * ただし、ビルドは通るが途中で例外が発生し動かなくなる。
 *
 * 初版作成：2023.01.01
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>

#define NUM_INF 999999999

using namespace std;

// プロトタイプ宣言
class Node;
map<string, Node> nodeMapInit();
void dijkstraSearth(map<string, Node> nodeMap, string startNode, string endNode);
map<string, int> initDistFromStart(map<string, Node> nodeMap, string startNode);
map<string, vector<string>> initMinPathFromStart(map<string, Node> nodeMap, string startNode);
bool isOnList(string value, vector<string> list);

// ノード（頂点）クラス
class Node {
public:
	map<string, int> routes;

	Node(map<string, int> nextRoutes) {
		this->routes = nextRoutes;
	};

	Node() {};
};


int main() {
	// 頂点と経路の初期化・取得
	map<string, Node> nodeMap = nodeMapInit();

	string startNode = "A";
	string goalNode = "E";

	// 検索・表示
	dijkstraSearth(nodeMap, startNode, goalNode);

	return 0;
}

// グラフ情報を初期化します。
map<string, Node> nodeMapInit() {
	map<string, Node> rtnList;

	// A
	map<string, int> aNextRoutes = {
		{"B", 7},
		{"C", 4},
		{"D", 3}
	};
	rtnList.emplace("A", aNextRoutes);

	// B
	map<string, int> bNextRoutes = {
		{"C", 1},
		{"E", 2},
	};
	rtnList.emplace("B", bNextRoutes);

	// C

	map<string, int> cNextRoutes = {
		{"B", 1},
		{"E", 6},
	};
	rtnList.emplace("C", cNextRoutes);

	// D
	map<string, int> dNextRoutes = {
		{"E", 5},
	};
	rtnList.emplace("D", dNextRoutes);

	// E
	map<string, int> eNextRoutes = {
	};
	rtnList.emplace("E", eNextRoutes);

	return rtnList;
}

// ダイクストラ法処理本体
void dijkstraSearth(map<string, Node> nodeMap, string startNode, string endNode) {
	// スタート地点からの最小距離を格納するマップ
	map<string, int> minDistFromStart = initDistFromStart(nodeMap, startNode);
	// スタート地点から最小距離となる経路を格納するマップ
	map<string, vector<string>> minPathFromStart = initMinPathFromStart(nodeMap, startNode);
	// 最小距離が確定している頂点一覧
	vector<string> updatedNodes(0);

	// 検索が完了するまで繰り返す
	bool inSearch = true;
	while (inSearch) {
		// もとのminPathFromStartは書き換えが発生するため正常に繰り返し処理ができないことがあるため、
		// 一時変数としてコピーし処理を行う
		map<string, Node> tmpMinPathFromStart;
		memcpy(&tmpMinPathFromStart, &minPathFromStart, sizeof(minPathFromStart));

		// まだ検索対象の頂点でない場合は処理を中断
		for (const auto& item : minPathFromStart) {
			if (item.second.size() == 0) {
				continue;
			}

			// 検索対象の頂点の添え字を取得
			auto searchBaseNodeName = item.second.back();

			// 最小距離が確定している頂点だった場合は処理を中断
			if (isOnList(searchBaseNodeName, updatedNodes)) {
				continue;
			}

			// 対象の頂点の行き先の頂点について最小距離・経路を更新
			Node targetNode = nodeMap[searchBaseNodeName];
			for (const auto& nextRoute : targetNode.routes) {
				int tmpDist = minDistFromStart[searchBaseNodeName] + nextRoute.second;

				// 最小距離を更新
				if (tmpDist < minDistFromStart[searchBaseNodeName]) {
					minDistFromStart[searchBaseNodeName] = tmpDist;
				}

				// 最短経路を更新
		// ここまでの最小経路を一時変数に格納
				vector<string> tmpNewPath;
				vector<string> copyBasePath = minPathFromStart[searchBaseNodeName];
				tmpNewPath.insert(tmpNewPath.end(), copyBasePath.begin(), copyBasePath.end());

				// 最小距離となる経路を更新
				tmpNewPath.emplace_back(nextRoute.first);
				minPathFromStart[nextRoute.first] = tmpNewPath;
			}

			// 更新済み頂点に更新
			updatedNodes.push_back(searchBaseNodeName);
		}

		// for debug
		std::cout << "OK" << endl;
		inSearch = false;
	}

	// 最小距離を更新
	std::cout << "distance: " << minDistFromStart[endNode] << endl;

	// 最小距離の経路を表示
	std::cout << "route: ";
	for (auto node : minPathFromStart[endNode]) {
		std::cout << node;
		if (node == endNode) {
			break;
		}
		std::cout << "-> ";
	}

	return;
}

// 最小距離一覧を初期化
map<string, int> initDistFromStart(map<string, Node> nodeMap, string startNode) {
	map<string, int> rtnMap;

	for (auto targetNode : nodeMap) {
		rtnMap.emplace(targetNode.first, NUM_INF);
	}

	rtnMap[startNode] = 0;

	return rtnMap;
}

// 最小距離の経路を初期化
map<string, vector<string>> initMinPathFromStart(map<string, Node> nodeMap, string startNode) {
	map<string, vector<string>> rtnMap;

	for (auto targetNode : nodeMap) {
		rtnMap.emplace(targetNode.first, vector<string>(0));
	}

	rtnMap[startNode].push_back(startNode);

	return rtnMap;
}

// 引数valueが対象のlistに存在するか判定
bool isOnList(string value, vector<string> list) {
	for (const auto& item : list) {
		if (item == value) {
			return false;
		}
	}

	return true;
}
