#include <iostream>
#include <vector>
using namespace std;

/* 18.
* �Ľ�Į �ﰢ�� �����
* reserve => vector �� capacity �� �ø�
* resize => vector �� size �� �ø�
* capacity �� �ø�, ���Ͱ� ������ ���Ҵ��� ���� ������, ���� �� ������ ������ ���� ����
* ������ size �� ������ ������ �� �ִ�
* ���� ���� ���� ������ �̸� �Ҵ��ϴ� �Ŷ��, resize �� ��� �Ѵ�
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

// n_C_k �� ����ϴ� �Լ�
int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        // �ݺ����� ���鼭 �ٷιٷ� ���ϰ� ������ �ǳ��� => ���������� �� ���������� �� �𸣰ڴ�
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

/*
    2D prefix sum array ����� ���
    1 1+2
    1+3 2+4+1+3

    1 2+1
    3+1 4+3+2+1

    ���� / ���� �������� prefix sum �� ���� ����
    ���� / ���� �������� prefix sum �� ���ϸ� �ȴ�

    ���� ������, �ǹ̸� �����ϸ鼭 �ǹ̸� �����ϰ�, �ߺ��� ������ ����... ���� �ʾƵ� �ȴ�
*/
void getPrefixArray(vector<vector<int>> v) {
    // �־��� ���Ϳ� ���� ũ��� ���� => reserve, resize ���ʿ�
    vector<vector<int>> prefixSum = v;

    // ���� ù��° column �� �����ؿ´�
    for (int row = 0; row < prefixSum.size(); row++) {
        prefixSum[row][0] = v[row][0];
    }

    // �� ����, column ���� prefix sum �� ���Ѵ�
    for (int col = 1; col < prefixSum[0].size(); col++) {
        for (int row = 0; row < prefixSum.size(); row++) {
            prefixSum[row][col] = prefixSum[row][col - 1] + v[row][col];
        }
    }

    // column's prefix sum ���� row ���� prefix sum �� ���Ѵ� => ��ü 2D prefix sum array �� ��� �ȴ�
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