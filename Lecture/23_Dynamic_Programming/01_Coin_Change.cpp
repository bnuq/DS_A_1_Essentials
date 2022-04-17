#include <vector>
#include <iostream>
#include <climits>

using namespace std;

// Bottom Up Approach
// denoms 를 이용해서, m 값을 만들 때
// 가장 적게 사용되는 개수를 구하자
int minNumberOfCoinsForChange(int m, vector<int> denoms) {
    
    // Memoisation 초기화 => 얼마가 최소인지 모르니까 최대값 저장
    vector<int> dp(m+1, INT_MAX);
    dp[0] = 0; // 0 을 만들 때는 아무것도 사용하지 않으면 되니까, 0 개가 쓰인다

    // 1 부터 m 까지, i 를 만들 수 있는 경우의 수를 조사한다
    for(int i = 1; i <= m; i++) {
        
        // i 값을 만들기 위해 denoms 중 하나를 사용한다고 가정하고
        // 그 나머지를 만드는 데 필요한 개수를 모두 조사
        // 가장 최소값을 구한다
        for(int c : denoms) {

            if(i - c >= 0 and    // denoms 중 하나를 썼을 때 나머지가 양수여야 하고
            dp[i-c] != INT_MAX) { // 나머지를 만들 수 있어야 한다

                // dp[i] 에는 이전 다른 c 를 통해 만든 개수가 저장되어 있다
                dp[i] = min(dp[i], dp[i-c] + 1);
               }
        }
    }

    return dp[m] == INT_MAX ? -1 : dp[m];
}