/*
* 망고 나무가 표시되어 있는 2D 배열
* 가로로 한번, 세로로 한번 나누어 영역을 4개로 나눈다
* 가장 마지막에 땅을 고를 수 있다
* 가져올 수 있는 가장 많은 망고 나무 개수는?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
using namespace std;


/*
* 포인트 = 2D prefix sum array 를 만들어
* (0,0) 애서 특정 지점 내 망고 나무의 개수를 미리 계산한다
* 그래서 어느 지점을 잘랐을 때, 각 구역 별 망고 나무 개수를 바로 파악할 수 있게 한다
*/

vector<int> getMangoTree(vector<vector<char>> land) {
	int rowNum = land.size();
	int colNum = land[0].size();

	// 받은 벡터로부터, 망고 나무 위치, 개수를 파악한다
	vector<vector<int>> mangoCount{};
	mangoCount.resize(land.size());
	for (int i = 0; i < mangoCount.size(); i++) {
		//mangoCount[i].resize(land[i].size());
		for (int j = 0; j < land[i].size(); j++) {
			if (land[i][j] == '#') mangoCount[i].push_back(1);
			else mangoCount[i].push_back(0);
		}
	}
	
	
	// 2D prefix sum array 를 구한다
	// 복사해서 생성 => 첫번째 행 or 첫번째 열이 이미 같은 상황
	vector<vector<int>> prefixSum = mangoCount;

	
	// row 들의 prefix sum 먼저 구하고
	for (int row = 1; row < prefixSum.size(); row++) {
		for (int col = 0; col < prefixSum[row].size(); col++) {
			prefixSum[row][col] += prefixSum[row - 1][col];
		}
	}

	// row's prefix sum => column prefix sum 구한다
	for (int col = 1; col < prefixSum[0].size(); col++) {
		for (int row = 0; row < prefixSum.size(); row++) {
			prefixSum[row][col] += prefixSum[row][col - 1];
		}
	}

	int maximum{ 0 }, xcord{}, ycord{};

	// 이후 prefix sum 배열 전체를 조회하면서, 각 구역 별 망고 나무 개수를 구한다
	for (int row = 0; row < prefixSum.size(); row++) {
		for (int col = 0; col < prefixSum[row].size(); col++) {
			int part1 = prefixSum[row][col];
			int part2 = prefixSum[row][colNum - 1] - part1;
			int part3 = prefixSum[rowNum - 1][col] - part1;
			int part4 = prefixSum[rowNum - 1][colNum - 1] - part2 - part3 + part1;

			int temp = min({ part1, part2, part3, part4 });

			if (temp > maximum) {
				maximum = temp;
				xcord = row;
				ycord = col;
			}
		}
	}


	for (auto x : mangoCount) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (auto x : prefixSum) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;

	

	return vector<int>{xcord, ycord, maximum};
}


int main() {
	vector<vector<char>> mango{
		{'#', '#', '#', '.', '.', '#'},
		{'#', '.', '.', '#', '#', '.'},
		{'.', '#', '.', '.', '.', '.'},
		{'#', '#', '#', '.', '.', '#'},
		{'#', '.', '.', '#', '#', '.'},
		{'.', '#', '.', '.', '.', '.'},
		{'.', '#', '.', '#', '.', '#'},
		{'#', '#', '.', '#', '#', '.'}
	};


	vector<int> res{ getMangoTree(mango) };
	for (auto x : res) {
		cout << x << " ";
	}
	cout << endl;
}