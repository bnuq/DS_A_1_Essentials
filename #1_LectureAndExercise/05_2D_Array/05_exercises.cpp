#include <iostream>
#include <vector>
using namespace std;

/* 18.
* 파스칼 삼각형 만들기
* reserve => vector 의 capacity 를 늘림
* resize => vector 의 size 를 늘림
* capacity 가 늘면, 벡터가 앞으로 재할당할 일은 없지만, 내가 그 영역을 참조할 수는 없다
* 오로지 size 내 범위만 참조할 수 있다
* 따라서 쓰고 싶은 영역을 미리 할당하는 거라면, resize 를 써야 한다
*/
vector<vector<int>> my_printPascal(int n)
{
    // your code goes here
    vector<vector<int>> res{};
    res.resize(n);

    for (int row = 0; row < n; row++) {
        for (int col = 0; col <= row; col++) {
            if (col == 0) {
                res[row].resize(row + 1);
                res[row][col] = 1;
            }
            else if (col == row) res[row][col] = 1;
            else {
                res[row][col] = res[row - 1][col - 1] + res[row - 1][col];
            }
        }
    }
    return res;
}

// n_C_k 를 계산하는 함수
int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        // 반복문을 돌면서 바로바로 곱하고 나눠도 되나봐 => 수학적으로 왜 가능한지는 잘 모르겠다
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

/*
    2D prefix sum array 만드는 방법
    1 1+2
    1+3 2+4+1+3

    1 2+1
    3+1 4+3+2+1

    가로 / 세로 방향으로 prefix sum 을 구한 다음
    세로 / 가로 방향으로 prefix sum 을 구하면 된다

    만들 떄부터, 의미를 생각하면서 의미를 생각하고, 중복된 영역을 빼고... 하지 않아도 된다
*/
void getPrefixArray(vector<vector<int>> v) {
    // 주어진 벡터와 같은 크기로 생성 => reserve, resize 불필요
    vector<vector<int>> prefixSum = v;

    // 먼저 첫번째 column 을 복사해온다
    for (int row = 0; row < prefixSum.size(); row++) {
        prefixSum[row][0] = v[row][0];
    }

    // 그 다음, column 들의 prefix sum 을 구한다
    for (int col = 1; col < prefixSum[0].size(); col++) {
        for (int row = 0; row < prefixSum.size(); row++) {
            prefixSum[row][col] = prefixSum[row][col - 1] + v[row][col];
        }
    }

    // column's prefix sum 에서 row 들의 prefix sum 을 구한다 => 전체 2D prefix sum array 를 얻게 된다
    for (int row = 1; row < prefixSum.size(); row++) {
        for (int col = 0; col < prefixSum[row].size(); col++) {
            prefixSum[row][col] += prefixSum[row - 1][col];
        }
    }

    for (auto x : prefixSum) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}