#include <vector>
using namespace std;

/* 
    어떤 값들이 주어진다 => 각각에 대응되는 가격이 존재한다
    배낭에 그것들을 넣는다, 배낭에는 넣을 수 있는 무게 한계가 있다
    배낭의 한계를 넘지 않으면서, 가격이 최대가 되는 경우를 구하고 싶다
 */


/* 
    Recursive Code => Top Down

    넣을 후보가 되는 값들의 배열에서 => 가장 오른쪽에 있는 것 부터 조사
    그것이 들어가는 경우
        => 나머지 무게로 만드는 최대 가격 조사
    그것이 안 들어가는 경우
        => 만들어질 수 있는 최대 가격 조사
 */
int knapsack(int wts[], int prices[], int N, int W) {

    // base case
    // 더이상 배낭에 넣을 것이 없거나, 배낭에 넣을 공간이 없거나
    if(N == 0 or W == 0) {
        return 0; // 만드는 가격은 0 이다
    }

    // recursive case
    int inc = 0, exc = 0; // N 번째 요소가 들어가는 경우와 안 들어가는 경우

    if(wts[N-1] <= W) { // 들어갈 수 있으면
        // 해당 요소가 들어가고, 나머지 들로 만들 수 있는 최대 가격을 구한다
        inc = prices[N-1] + knapsack(wts, prices, N-1, W - wts[N-1]);
    }
    // 안 들어가는 경우에 대해서도 조사
    exc = knapsack(wts, prices, N-1, W);

    return max(inc, exc);
}


// DP 이용하는 방법에 대해 알아보자
int knapsackDP(int wts[], int prices[], int N, int W) {

    // N, W 에 따른 값을 저장하는 2차원 배열이 있다고 생각
    // 밑에서부터 값을 찾아 넣는다
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    // dp[0][i] = 0 => 넣을 게 없으니까
    // dp[i][0] = 0 => 넣을 공간이 없으니까

    // dp[1][1] 부터 채우기 시작한다
    // 한 개만 쓸때, 두 개 쓸때 ... 순서로 진행
    for(int n = 1; n <= N; n++) {
        for(int w = 1; w = W; w++) {

            /* 
                항상 이전 row 의 값을 이용해서
                현재 row 의 값을 채운다
             */

            // dp 배열에 값을 채우기 위해서는 2 가지 상황 모두 고려하고 구해야 한다
            int inc = 0, exc = 0;

            if(wts[n-1] <= W) { // n 번째 요소를 넣을 수 있을 때
                inc = prices[n-1] + dp[n-1][w - wts[n-1]];
            }
            exc = dp[n-1][w];
        }
    }

    return dp[N][W];
}