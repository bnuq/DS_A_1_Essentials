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

        // 이항 계수를 넣은 벡터를 만든 다음에
        vector<int> v;
        for (int i = 0; i <= line; i++)
        {
            v.push_back(binomialCoeff(line, i));
        }

        // 벡터에 벡터를 집어 넣는 방식으로
        res.push_back(v);
    }
    return res;
}

// nCk 를 계산하는 함수
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


// reserve => vector 의 capacity 를 늘림
// resize => vector 의 size 를 늘림
// capacity 가 늘면, 벡터가 앞으로 재할당할 일은 없지만, 내가 그 영역을 참조할 수는 없다
// 오로지 size 내 범위만 참조할 수 있다
// 따라서 쓰고 싶은 영역을 미리 할당하는 거라면, resize 를 써야 한다
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