#include <iostream>
using namespace std;

void basic() {
	int x{ 10 };
	int* xptr{ &x };
	int** xxptr{ &xptr };

	int& y{ x };

	// Dynamic array
	int arrSize{ 10 };
	int* arr = new int[arrSize];
	delete[] arr;
}

// Heap 공간에서는 기존 방식대로 2D array 를 만들 수 없다
void create2DArray(int rows, int cols) {

	// 먼저 포인터의 배열을 만들고
	int** arr = new int* [rows];

	//allocate memory for each row
	//각 포인터마다 배열을 다시 할당
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	//init the array with increasing list of nos
	int value = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = value;
			value++;
		}
	}
	
	//Delete 할때는 반대 순서로 진행한다
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}