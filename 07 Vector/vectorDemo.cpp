/*
	vector 재할당할 때는 기존 길이의 2배로 재할당한다
*/
#include <iostream>
#include <vector>

using namespace std;


int main() {
	int row{}, col{};
	cin >> row >> col;
	
	// Fill Constructor, 이용해서 2차원 벡터 만들기
	// 그냥 생각나서 해봄
	vector< vector<int> > vec(row, vector<int>(col, 10));

	for (auto x : vec) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}

	
}