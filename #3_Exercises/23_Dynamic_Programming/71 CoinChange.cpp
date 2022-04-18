#include<bits/stdc++.h>
using namespace std;

/* 
    코인 중 0번째 코인을 시작점으로 두고 -
    n 번째 까지를 사용할 코인 영역으로 설정할 때

    s 를 만들 수 있는 조합의 수를 구하는 helper function

    각 상황을 표현하는 데 필요한 이름표에 속성이 2개 라는 것과
    각각의 속성을 제대로 파악하는 것이 중요하구나
 */
long long coinChange(int s, int n , vector<int>& a, long long dp[500][100])
{
    // 사용하는 동전 인덱스가 음수거나, 만드려는 값이 음수면 그대로 종료
    if (n < 0 || s < 0) return 0;

    // 0 을 만든다는 것 = 아무것도 사용하지 않으면 된다 => 1
    if (s == 0) return 1;

    // 계산된 값이 있으면, 그것 사용
    if (dp[s][n] != 0) return dp[s][n];
    

    // n 번째 동전을 사용하지 않고 s 를 만드는 조합의 수를 구하고
    // n 번째 동전이 절대 사용되지 않는 경우
    long long op1 = coinChange(s, n - 1, a, dp);

    // n 번째 동전을 사용하고, 그 나머지 값을 만드는 조합의 수를 구하는데
    // 사용하는 동전의 범위가 변하지 않는다
    // n 번째가 중복되서 사용되는 경우를 모두 계산
    // 중복해서 사용할 수 있으니까, 그냥 한번 이상 사용되는 모든 경우를 하나로 퉁쳐
    // 구하는 값만 변하고 사용하는 범위는 바뀌지 않는다
    long long op2 = coinChange(s - a[n], n, a, dp);


    // 두 경우는 n 번째 값이 사용되거나, 사용되지 않은 경우의 수니까 서로 중복되지 않는다
    // 그래서 두 수를 더하면 0~n 범위 내 동전들을 이용해서 s 를 만드는 조합의 수가 나온다
    return dp[s][n] = op1 + op2;
}


/* 
    coins 에 저장된 동전 값들로 n 을 만드는 조합의 개수 구하기
    조합의 수를 구해야 해서, 중복되는 것을 빼야 했다
    이거 중복 제거 어떻게 함?
 */
long long findCombinations(int n, vector<int> coins)
{
    /* 
        만들고자 하는 총합과
        그 총합을 만드는 데 사용되는 동전의 개수, 인덱스가
        
        이름표로 사용된다 => 2차원 배열을 사용해야 하고
        어떤 n 값과 어떤 coins 배열이 주어질 지 모르니까
        그냥 상수 값으로 배열을 만들어놨구나
     */
    long long dp[500][100] = {{0}};

    /* 
        helper function 사용
     */
    return coinChange(n, coins.size()-1, coins, dp);
}