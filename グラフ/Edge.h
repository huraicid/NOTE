#pragma once
class Edge {
public:
	/// <summary>
	/// �s��̒��_�ԍ�
	/// </summary>
	int to;

	/// <summary>
	/// �d��
	/// </summary>
	long long w;

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="to">�s��̒��_�ԍ�</param>
	/// <param name="w">�d��</param>
	Edge(int to, long long w) : to(to), w(w) {};
};