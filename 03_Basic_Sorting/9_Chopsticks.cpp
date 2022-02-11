//Expected Complexity: O(N logN)


#include <vector>
#include <algorithm>
using namespace std;


int pairSticks(vector<int> length, int D)
{
    // your code goes here
    // 일단 정렬을 해 => 정렬을 하면, 이후 처리가 훨씬 편하다
    // 배치가 어느정도 확정되니까
    sort(length.begin(), length.end());
    int res = 0;

    for(int i=0; i<length.size()-1; i++)
    {
        // 헐 똑같네 여기서도 2개씩 비교하네
        // 최대한 인접한 것들끼리 짝을 짓는 게, 가장 구하기 쉬운 방법 인가봐
        if (length[i + 1] - length[i] <= D) { res++; i++;}
    }

    return res;
}


int my_pairSticks(vector<int> length, int D)
{
    // your code goes here
    // 일단 정렬 먼저 한다
    sort(length.begin(), length.end());

    // 항상 비교하는 인덱스는 1 차이만 나겠구나
    int i1{ 0 }, i2{ 1 }, count{ 0 };


    while (i1 < length.size() and i2 < length.size()) {
        if (length[i2] - length[i1] <= D) {
            count++;

            // 다음 페어로 넘어간다
            i1 += 2;
            i2 += 2;
        }
        // 이번에 차이가 많이난 경우, i2 는 유지하고 하나만 더 검사한다
        else {
            i1 = i2;
            i2 += 1;
        }

        
    }

    return count;

}