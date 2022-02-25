#include <vector>
#include <iostream>
using namespace std;


bool canGo(vector<vector<int>>& res, vector<string>& arr, int row, int col, int N, int M) {
    if (row < 0 or row >= N) return false;
    if (col < 0 or col >= M) return false;
    if (arr[row][col] == 'X') return false;

    //if (res[row][col] != -1) return false;
    
    return true;
}


// [row][col] 에서 다음으로 넘어가려는 상황
bool getPath(vector<vector<int>>& res, vector<string>& arr, int row, int col, int N, int M) {
    if (row == N - 1 and col == M - 1) {
        return true;
    }

    if (canGo(res, arr, row, col + 1, N, M) && res[row][col+1] != 1) { // right
        res[row][col + 1] = 1;
        if (getPath(res, arr, row, col + 1, N, M)) return true;
        else res[row][col + 1] = 0;
    }
    if (canGo(res, arr, row + 1, col, N, M) and res[row+1][col] != 1) { // down
        res[row + 1][col] = 1;
        if (getPath(res, arr, row + 1, col, N, M)) return true;
        else res[row + 1][col] = 0;
    }
    if (canGo(res, arr, row, col - 1, N, M) and res[row][col-1] != 1) { // left
        res[row][col - 1] = 1;
        if (getPath(res, arr, row, col - 1, N, M)) return true;
        else res[row][col - 1] = 0;
    }
    if (canGo(res, arr, row - 1, col, N, M) and res[row - 1][col] != 1) { // up
        res[row - 1][col] = 1;
        if (getPath(res, arr, row - 1, col, N, M)) return true;
        else res[row - 1][col] = 0;
    }

    return false;
}

vector<vector<int>> ratAndMice(vector<string> arr) {
    int N{ static_cast<int>(arr.size())};
    int M{ static_cast<int>(arr[0].size())};

    vector<vector<int>> res(N, vector<int>(M, 0));
    res[0][0] = 1;

    getPath(res, arr, 0, 0, N, M);
    return res;
}

int main() {
    vector<string> arr{
        "OXOO",
        "OOOX",
        "XOXO",
        "XOOX",
        "XXOO"
    };

    /*vector<string> arr{
        "OXO",
        "OOX",
        "XOO"
    };*/

    vector<vector<int>> res{ ratAndMice(arr) };

    //for (auto& x : res) {
    //    for (auto& y : x)
    //        if (y != 1) y = 0;
    //}


    for (auto x : res) {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}