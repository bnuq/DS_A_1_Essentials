#include <iostream>
#include <vector>
using namespace std;

/*
Binary Search �� Recursion ���� ��Ÿ���� => Divide and Conquer
Binary Search ���� mid Ž���� �������� ��,
���� �˻������� �����ϴ� �� = Divide
����, �ش� �������� Binary Search ����� ã�� �� = Conquer
*/
int doBinarySearch(const vector<int>& v, int x, int left, int right) {
    // �˻������� ��� ��� => ���� ����
    if (left > right) return -1;

    int mid = (left + right) / 2;   // Binary Search => �ϴ� �߰����� �˻��غ���
    if (v[mid] == x) return mid;

    // Divide
    int lLeft = left, lRight = mid - 1;     // ���� ����
    int rLeft = mid + 1, rRight = right;    // ������ ����
    int res{};

    // mid ���� ���� ���� �˻����� ���� => ��� ã�� == Conquer
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
2D array �� row �� �����ϰ�, col �� �����϶� => Merge Sort ��� == Divide and Conquer, �����ؼ� �����Ѵ�
������ �ʹ� ũ�� �����ϴϱ� recursion => ���� ������ �ɰ���, divide
�׸��� ����, conquer �� �ϸ鼭 ũ�⸦ �ٽ� ���� Ű��� => ���� �Ž����� �������� ���� ��, �� �κ��� �̹� �����Ǿ� �ִ� ���°�
���� ������ ���� ��Ƽ� �� ū ������ ����� ���̴�

�ַ�Ǻ��� �� �ڵ尡 �� ���� ������, ������ �츰��
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