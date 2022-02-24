#include <iostream>
#include <vector>
using namespace std;


/*
Binary Search 를 Recursion 으로 나타내라 => Divide and Conquer
우선 현재 mid 탐색, key 와 같은 지 찾는다 => 현재 단계 작업, Conquer
다음 검색범위를 설정하는 것 = Sub Problems 로 나누는 것, Divide
*/
int doBinarySearch(const vector<int>& v, int x, int left, int right) {
    // Base Case
    // 검색범위를 벗어난 경우 => 실패 리턴
    if (left > right) return -1;

    int mid = (left + right) / 2;   // Binary Search => 일단 중간값을 검색해본다
    if (v[mid] == x) return mid;    // 현재 단계 작업

    // Divide, Sub Problems 로 나누기
    int lLeft = left, lRight = mid - 1;     // 왼쪽 범위
    int rLeft = mid + 1, rRight = right;    // 오른쪽 범위
    int res{};

    // mid 값에 따라서 다음 검색범위 결정 => 현재 문제 구간을, 작은 구간으로 나눈다
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
    2D array 를 row 로 정렬하고, col 로 정렬하라 => Merge Sort 사용 => Divide and Conquer
    현재 단계에서 해결해보려 하고, 안되면 더 작은 구간으로 문제를 쪼갠다    
    나는 정복된 것을 모아서 더 큰 정복을 만드는 것이다
    솔루션보다 내 코드가 더 보기 좋으니, 내것을 살린다
*/
// 정해진 구간 내 rows 를 정렬하는 것
void rowMerge(int xL, int xR, int yU, int yD, vector<vector<int>>& v) {
    for (int row = yU; row <= yD; row++) { // 각각의 row 에 대해서 정렬을 한다
        vector<int> temp{};
        int left = xL;
        int mid = (xL + xR) / 2;    // mid 를 기준으로 좌우 정렬이 된 구간이라 가정
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
        // temp 에 값을 정렬한 다음 v 에 넣는다
        for (int col = xL, i = 0; col <= xR; col++, i++) {
            v[row][col] = temp[i];
        }
    }
}
// 정해진 구간 내 cols 를 정렬하는 것
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
    // Base Case
    if (xL > xR or yU > yD) return;
    if (xL == xR and yU == yD) return;

    int xMid = (xL + xR) / 2;
    int yMid = (yU + yD) / 2;

    // Sub Problem 으로, 현재 문제의 크기를 잘게 나눈 다음 
    Divide(xL, xMid, yU, yMid, v);
    Divide(xMid + 1, xR, yU, yMid, v);
    Divide(xL, xMid, yMid + 1, yD, v);
    Divide(xMid + 1, xR, yMid + 1, yD, v);
    // 현재 단계 작업을 한다 => row, col 정렬
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