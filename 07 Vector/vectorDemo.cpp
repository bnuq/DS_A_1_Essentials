/*
	vector ���Ҵ��� ���� ���� ������ 2��� ���Ҵ��Ѵ�
*/
#include <iostream>
#include <vector>

using namespace std;


int main() {
	int row{}, col{};
	cin >> row >> col;
	
	// Fill Constructor, �̿��ؼ� 2���� ���� �����
	// �׳� �������� �غ�
	vector< vector<int> > vec(row, vector<int>(col, 10));

	for (auto x : vec) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}

	
}