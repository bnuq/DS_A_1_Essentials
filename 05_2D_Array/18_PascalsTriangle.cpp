#include <iostream>
#include <vector>
using namespace std;

//Expected Time Complexity: O(n^3)
//Hint: Use Binomial Coeffiecients
int binomialCoeff(int n, int k);

// Function to print first
// n lines of Pascal's
// Triangle
vector<vector<int>> printPascal(int n)
{
    // Iterate through every line and
    // print entries in it
    vector<vector<int>> res;
    for (int line = 0; line < n; line++)
    {
        // Every line has number of
        // integers equal to line
        // number

        // ���� ����� ���� ���͸� ���� ������
        vector<int> v;
        for (int i = 0; i <= line; i++)
        {
            v.push_back(binomialCoeff(line, i));
        }

        // ���Ϳ� ���͸� ���� �ִ� �������
        res.push_back(v);
    }
    return res;
}

// nCk �� ����ϴ� �Լ�
int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}


// reserve => vector �� capacity �� �ø�
// resize => vector �� size �� �ø�
// capacity �� �ø�, ���Ͱ� ������ ���Ҵ��� ���� ������, ���� �� ������ ������ ���� ����
// ������ size �� ������ ������ �� �ִ�
// ���� ���� ���� ������ �̸� �Ҵ��ϴ� �Ŷ��, resize �� ��� �Ѵ�
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

int main()
{
    vector<vector<int>> res = printPascal(10);

    for (auto x : res) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}