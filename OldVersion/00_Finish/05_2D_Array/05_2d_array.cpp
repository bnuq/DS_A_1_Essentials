#include <iostream>
using namespace std;

// c style 2d array �� argument �� ���� ����, col ������ �������־�� �Ѵ�
// col ���� ���� ���� 2d array �� ���� �� ����
//Passed by Reference
void print(int arr[][100], int n, int m) { // col ������ 100 ���� 2d �迭�� �� �� �ֵ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void cStyle2d() {
	// ������ ����, row ������ �ڵ����� �ľ��ϱ� ������ ������ �ʾƵ� ������,
	// col ������ Ȯ���� ������ �Ѵ�
	char numbers[][10] = {
		"one",
		"two",
		"three",
		"forty",
		"eight",
		"hundred",
	};
}

// �־��� 2d array ��Ҹ� ȸ���ϴ� �������� ���
void spiralPrint(int arr[][10], int n, int m) {
    // ȸ���ϸ鼭 �������� ��θ� �ε����� �̿��ؼ� ����
    // ��� �ϳ��ϳ��� ���󰡸鼭, ��¥ ȸ���� �Ѵٰ� �������� �ʰ�
    // ������ ��ü�� �ٶ�� ~ ���� ���ϴ� �ε����� ã�Ƴ��ٴ� ����
    int startRow = 0;
    int endRow = n - 1;
    int startCol = 0;
    int endCol = m - 1;

    //Outer Loop (Traverse array boundary)
    while (startCol <= endCol and startRow <= endRow) {
        // start row -> end col -> end row -> start col ������ ����� �Ѵ�
        //Start Row
        for (int col = startCol; col <= endCol; col++) {
            cout << arr[startRow][col] << " ";
        }
        //End Col
        for (int row = startRow + 1; row <= endRow; row++) {
            cout << arr[row][endCol] << " ";
        }
        //End Row
        for (int col = endCol - 1; col >= startCol; col--) {
            if (startRow == endRow) {
                break;
            }
            cout << arr[endRow][col] << " ";
        }
        //Start Col
        for (int row = endRow - 1; row >= startRow + 1; row--) {
            //Avoid Duplicate Printing of elements
            if (startCol == endCol) {
                break;
            }
            cout << arr[row][startCol] << " ";
        }

        //update the variables to point to inner spiral
        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
}
/* �̰� ���࿡ ��¥ �迭 ��� �ϳ��ϳ� �i�ư��鼭, ȸ�� ����� ������� ������ 2�� ����������
�ε��� ����Ѵٰ� �Ӹ� �������� �Ŵ�. �׷���, ��ü�� �ٶ󺸰� �ε����� ������ ��Ÿ���ϱ� �ξ� ���ݾ�
�ణ �̷� �� ����� ��*/

/* staircase sort
2d array �� row �� col �� ���ĵǾ� ���� ��, ���ϴ� ���� ������ �˻��ϴ� ���
�����¿��� ���ĵǾ� �ִٴ� ���� �� �̿��ؾ� �Ѵ�...
���� ��ܿ��� �˻��� �����Ѵ�
���ϴ� ���� ���� ������ ũ�� ~ ������ ������
���ϴ� ���� ���� ������ �۴� ~ �������� ����
*/