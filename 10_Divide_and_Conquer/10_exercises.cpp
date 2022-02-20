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