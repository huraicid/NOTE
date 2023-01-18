#pragma once
class Edge {
public:
	/// <summary>
	/// 行先の頂点番号
	/// </summary>
	int to;

	/// <summary>
	/// 重み
	/// </summary>
	long long w;

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="to">行先の頂点番号</param>
	/// <param name="w">重み</param>
	Edge(int to, long long w) : to(to), w(w) {};
};