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

// Heap ���������� ���� ��Ĵ�� 2D array �� ���� �� ����
void create2DArray(int rows, int cols) {

	// ���� �������� �迭�� �����
	int** arr = new int* [rows];

	//allocate memory for each row
	//�� �����͸��� �迭�� �ٽ� �Ҵ�
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
	
	//Delete �Ҷ��� �ݴ� ������ �����Ѵ�
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}