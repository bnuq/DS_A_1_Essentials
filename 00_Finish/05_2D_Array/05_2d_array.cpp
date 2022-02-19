#include <iostream>
using namespace std;

// c style 2d array 를 argument 로 받을 때는, col 개수를 지정해주어야 한다
// col 값이 같지 않은 2d array 는 받을 수 없다
//Passed by Reference
void print(int arr[][100], int n, int m) { // col 개수가 100 개인 2d 배열만 올 수 있따
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void cStyle2d() {
	// 정의할 때도, row 개수는 자동으로 파악하기 떄문에 써주지 않아도 되지만,
	// col 개수는 확실히 밝혀야 한다
	char numbers[][10] = {
		"one",
		"two",
		"three",
		"forty",
		"eight",
		"hundred",
	};
}

// 주어진 2d array 요소를 회전하는 방향으로 출력
void spiralPrint(int arr[][10], int n, int m) {
    // 회전하면서 지나가는 경로를 인덱스를 이용해서 저장
    // 요소 하나하나를 따라가면서, 진짜 회전을 한다고 생각하지 않고
    // 위에서 전체를 바라봐 ~ 내가 원하는 인덱스를 찾아낸다는 느낌
    int startRow = 0;
    int endRow = n - 1;
    int startCol = 0;
    int endCol = m - 1;

    //Outer Loop (Traverse array boundary)
    while (startCol <= endCol and startRow <= endRow) {
        // start row -> end col -> end row -> start col 순서로 출력을 한다
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
/* 이걸 만약에 진짜 배열 요소 하나하나 쫒아가면서, 회전 모양을 만들려고 했으면 2중 루프문에서
인덱스 계산한다고 머리 빠개졌을 거다. 그런데, 전체를 바라보고 인덱스로 범위를 나타내니까 훨씬 쉽잖아
약간 이런 걸 배워야 돼*/

/* staircase sort
2d array 가 row 랑 col 로 정렬되어 있을 때, 원하는 값을 빠르게 검색하는 방법
상하좌워로 정렬되어 있다는 것을 잘 이용해야 한다...
우측 상단에서 검색을 시작한다
원하는 값이 현재 값보다 크다 ~ 밑으로 내려가
원하는 값이 현재 값보다 작다 ~ 왼쪽으로 간다
*/