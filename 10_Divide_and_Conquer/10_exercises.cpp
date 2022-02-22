#include <iostream>
#include <vector>
using namespace std;

/*
Binary Search 를 Recursion 으로 나타내라 => Divide and Conquer
Binary Search 에서 mid 탐색에 실패했을 때,
다음 검색범위를 설정하는 것 = Divide
이후, 해당 범위에서 Binary Search 결과를 찾는 것 = Conquer
*/
int doBinarySearch(const vector<int>& v, int x, int left, int right) {
    // 검색범위를 벗어난 경우 => 실패 리턴
    if (left > right) return -1;

    int mid = (left + right) / 2;   // Binary Search => 일단 중간값을 검색해본다
    if (v[mid] == x) return mid;

    // Divide
    int lLeft = left, lRight = mid - 1;     // 왼쪽 범위
    int rLeft = mid + 1, rRight = right;    // 오른쪽 범위
    int res{};

    // mid 값에 따라서 다음 검색범위 결정 => 결과 찾아 == Conquer
    if (v[mid] > x) res = doBinarySearch(v, x, lLeft, lRight);
    else res = doBinarySearch(v, x, rLeft, rRight);

    return res;
}
int binarySearch(vector<int> v, int x)
{
    // your code goes here
    return doBinarySearch(v, x, 0, v.size() - 1);
}


/*
2D array 를 row 로 정렬하고, col 로 정렬하라 => Merge Sort 사용 == Divide and Conquer, 분할해서 정복한다
문제가 너무 크고 복잡하니까 recursion => 작은 단위로 쪼갠다, divide
그리고 정복, conquer 를 하면서 크기를 다시 점점 키운다 => 따라서 거시적인 관점에서 봤을 때, 각 부분은 이미 정복되어 있는 상태고
나는 정복된 것을 모아서 더 큰 정복을 만드는 것이다

솔루션보다 내 코드가 더 보기 좋으니, 내것을 살린다
*/
void rowMerge(int xL, int xR, int yU, int yD, vector<vector<int>>& v) {
    for (int row = yU; row <= yD; row++) {
        vector<int> temp{};
        int left = xL;
        int mid = (xL + xR) / 2;
        int right = mid + 1;

        while (left <= mid and right <= xR) {
            if (v[row][left] < v[row][right]) {
                temp.push_back(v[row][left]);
                left++;
            }
            else {
                temp.push_back(v[row][right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(v[row][left]);
            left++;
        }

        while (right <= xR) {
            temp.push_back(v[row][right]);
            right++;
        }

        for (int col = xL, i = 0; col <= xR; col++, i++) {
            v[row][col] = temp[i];
        }

    }
}
void colMerge(int xL, int xR, int yU, int yD, vector<vector<int>>& v) {
    for (int col = xL; col <= xR; col++) {
        vector<int> temp{};
        int up = yU;
        int mid = (yU + yD) / 2;
        int down = mid + 1;

        while (up <= mid and down <= yD) {
            if (v[up][col] < v[down][col]) {
                temp.push_back(v[up][col]);
                up++;
            }
            else {
                temp.push_back(v[down][col]);
                down++;
            }
        }

        while (up <= mid) {
            temp.push_back(v[up][col]);
            up++;
        }

        while (down <= yD) {
            temp.push_back(v[down][col]);
            down++;
        }

        for (int row = yU, i = 0; row <= yD; row++, i++) {
            v[row][col] = temp[i];
        }

    }
}
void Divide(int xL, int xR, int yU, int yD, vector<vector<int>>& v) {
    if (xL > xR or yU > yD) return;
    if (xL == xR and yU == yD) return;

    int xMid = (xL + xR) / 2;
    int yMid = (yU + yD) / 2;

    Divide(xL, xMid, yU, yMid, v);
    Divide(xMid + 1, xR, yU, yMid, v);
    Divide(xL, xMid, yMid + 1, yD, v);
    Divide(xMid + 1, xR, yMid + 1, yD, v);

    rowMerge(xL, xR, yU, yD, v);
    colMerge(xL, xR, yU, yD, v);
}


int main() {
    /*vector<vector<int>> vec{
        {18, 9, 11},
        {1, 4, 15},
        {13, 23, 20}
    };
    Divide(0, 2, 0, 2, vec);*/

    vector<vector<int>> vec{
        {18, 4, 16, 8},
        {23, 13, 20, 11},
        {28, 24, 26, 25},
        {1, 30, 15, 19}
    };
    Divide(0, 3, 0, 3, vec);


    for (auto x : vec) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}