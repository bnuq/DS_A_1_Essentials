/*
std::pair 는 기본적으로 first 값을 기준으로 sort 되나
	first 가 같은 경우에, second 를 기준으로 정렬된다
*/
#include <vector>
using namespace std;

/* 22 => 매우 중요
이차원 배열의 요소들을 시계방향으로 회전시켜라
이때 추가적인 메모리를 사용하지 않고, 주어진 배열 내에서 작업하라

나 같은 경우, 밖->안 으로 들어오면서 각각의 요소들에 접근해서 직접 옮기려 했다

그런데, 해답의 경우엔 swap 을 사용 => 너무 간단하게 해결
*/
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size(); // n * n 배열이라 가정

    int a = 0;
    int b = n - 1;
    while (a < b) {
        for (int i = 0; i < (b - a); ++i) {
            // 하나의 요소에는 총 4개의 요소가 대응, 이 4개를 모두 시계방향으로 돌려주어야 한다
            // 그래서 나는 임시 객체를 하나 만들고, 거기에 저장을 하는 식으로 반복문을 돌려서 해결
            // 여기서는 matrix[a][a+i] 위치를 저장 장소로 사용, swap 을 이용해서 회전하는 것과 같은 효과를 만들었다
            // matrix[a][a+i] 위치를 기준으로 다른 위치의 값들이 들어왔다 나갔다를 반복하면서, 결과적으로 시계방향으로 회전한 결과와 같게 된다
            // 이걸 어떻게 알아~ 어쨌든 swap 함수를 잘 활용하자
            swap(matrix[a][a + i], matrix[a + i][b]);
            swap(matrix[a][a + i], matrix[b][b - i]);
            swap(matrix[a][a + i], matrix[b - i][a]);
        }

        // 밖 -> 안 으로 진행
        ++a;
        --b;
    }
}
void my_rotate(vector<vector<int>>& matrix) { // 내 버전
    int n = matrix.size();
    int oldTmp{}, newTmp{};

    for (int i = 0; i < n / 2; i++) { // 바깥 공간 에서 안쪽으로 진행
        for (int j = i; j < n - 1 - i; j++) { // 내부 요소들에 대해서
            int x{ i }, y{ j }, z{}; // 임시 저장
            oldTmp = matrix[x][y];
            // 한 요소마다 총 4번의 값 수정이 필요 => 그래야 시계방향 회전
            // 근데 이렇게 진행하니까, 변수도 복잡하고 코딩도 꼬이고 그랬다
            for (int k = 0; k < 4; k++, x = y, y = z) {
                newTmp = matrix[y][n - 1 - x];
                matrix[y][n - 1 - x] = oldTmp;
                oldTmp = newTmp;
                z = n - 1 - x;
            }

        }
    }
}



/* 23
2D 배열에서 0 을 가진 원소가 있는 행과 열을 모두 0으로 칠하라
*/
vector<vector<int>> makeZeroes(vector<vector<int>> arr) {
    vector<int> r, c;
    // 배열의 행과 열 사이즈를 미리 파악한다
    int n = arr.size(), m = arr[0].size();

    // 배열 전체를 돌면서 0을 찾는데
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                // 행 인덱스와 열 인덱스를 따로따로 저장한다 => 왜? 어차피 0을 채울 때, 행과 열을 따로 따로 처리하니까
                // 하나의 성분이였다고 해서 꼭 같이 저장할 필요가 없다, 어차피 따로따로 사용하니까, 따로 저장한다
                r.push_back(i); c.push_back(j);
            }
        }
    }

    // 결국 0을 쓰는 작업은 행과 열이 따로 작업한다, 둘이 꼭 같이 저장될 이유가 없다
    
    // row 값에 대해서
    for (auto x : r) {
        // row 전체를 0으로 채운다
        for (int i = 0; i < n; i++) {
            arr[x][i] = 0;
        }
    }
    // col 값에 대해서
    for (auto x : c) {
        // col 전체를 0으로 채운다
        for (int i = 0; i < n; i++) {
            arr[i][x] = 0;
        }
    }

    return arr;
}
