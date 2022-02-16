#include <vector>
#include <algorithm>
using namespace std;

/*
* std::pair 에 대한 default 정렬
* first 를 non-decreasing order 로 정렬
* first 가 같다면, second 를 non-decreasing order 로 정렬
*/

/* 9.
* 특정 값과 임의의 값의 배열이 주어질 때, 배열의 두 값의 차이로 특정 값 이하를
* 만들수 있는 경우의 수를 구하라
*/
int pairSticks(vector<int> length, int D)
{
    // 일단 배열 정렬을 먼저 한다 => 일단 값들이 정렬되어 있으면, 배열을 다루기 쉽다
    sort(length.begin(), length.end());
    int res = 0;
    for (int i = 0; i < length.size() - 1; i++)
    {
        // 최대한 값이 비슷한 것들 끼리 모아 차를 구해야, 최대한 많은 경우의 수를 만들 수 있다
        if (length[i + 1] - length[i] <= D) { res++; i++; } // i 증가, 2칸 증가 효과를 만든다
    }

    return res;
}

