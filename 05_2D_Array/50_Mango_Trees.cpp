/*
* ���� ������ ǥ�õǾ� �ִ� 2D �迭
* ���η� �ѹ�, ���η� �ѹ� ������ ������ 4���� ������
* ���� �������� ���� �� �� �ִ�
* ������ �� �ִ� ���� ���� ���� ���� ������?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
using namespace std;


/*
* ����Ʈ = 2D prefix sum array �� �����
* (0,0) �ּ� Ư�� ���� �� ���� ������ ������ �̸� ����Ѵ�
* �׷��� ��� ������ �߶��� ��, �� ���� �� ���� ���� ������ �ٷ� �ľ��� �� �ְ� �Ѵ�
*/

vector<int> getMangoTree(vector<vector<char>> land) {
	int rowNum = land.size();
	int colNum = land[0].size();

	// ���� ���ͷκ���, ���� ���� ��ġ, ������ �ľ��Ѵ�
	vector<vector<int>> mangoCount{};
	mangoCount.resize(land.size());
	for (int i = 0; i < mangoCount.size(); i++) {
		//mangoCount[i].resize(land[i].size());
		for (int j = 0; j < land[i].size(); j++) {
			if (land[i][j] == '#') mangoCount[i].push_back(1);
			else mangoCount[i].push_back(0);
		}
	}
	
	
	// 2D prefix sum array �� ���Ѵ�
	// �����ؼ� ���� => ù��° �� or ù��° ���� �̹� ���� ��Ȳ
	vector<vector<int>> prefixSum = mangoCount;

	
	// row ���� prefix sum ���� ���ϰ�
	for (int row = 1; row < prefixSum.size(); row++) {
		for (int col = 0; col < prefixSum[row].size(); col++) {
			prefixSum[row][col] += prefixSum[row - 1][col];
		}
	}

	// row's prefix sum => column prefix sum ���Ѵ�
	for (int col = 1; col < prefixSum[0].size(); col++) {
		for (int row = 0; row < prefixSum.size(); row++) {
			prefixSum[row][col] += prefixSum[row][col - 1];
		}
	}

	int maximum{ 0 }, xcord{}, ycord{};

	// ���� prefix sum �迭 ��ü�� ��ȸ�ϸ鼭, �� ���� �� ���� ���� ������ ���Ѵ�
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