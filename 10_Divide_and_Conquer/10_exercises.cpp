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