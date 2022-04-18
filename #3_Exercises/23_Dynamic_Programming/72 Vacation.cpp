#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using mi = map<int, int>;
using ml = map<ll, ll>;
using umi = unordered_map<int, int>;
using uml = unordered_map<ll, ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using vii = vector<pi>;
using viii = vector<ti>;
using vll = vector<pl>;
using vlll = vector<tl>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(x, v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back



// vector<tuple> 사용
int topDown(viii &v, int n, int i, int dp[][4], int prev)
{
    if (i == n) return 0;
    if (dp[i][prev] != -1) return dp[i][prev];

    int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

    /* 
        Top Down 방식
        이번 단계에 무엇을 골랐을 때
            그 뒤에 나올 수 있는 최대 값을  계산해
        고를 수 있는 경우 중에서
        최대 값을 구해 리턴한다
     */

    if (prev != 1) op1 = fi(v[i]) + topDown(v, n, i + 1, dp, 1);
    if (prev != 2) op2 = se(v[i]) + topDown(v, n, i + 1, dp, 2);
    if (prev != 3) op3 = th(v[i]) + topDown(v, n, i + 1, dp, 3);

    // 대입하면서 리턴
    return dp[i][prev] = max(op1, max(op2, op3));
}


int vacation(vector<int> a, vector<int> b, vector<int> c)
{
    viii v;
    int n = a.size();
    rep(i, n)
    {
        v.pb(mt(a[i], b[i], c[i]));
    }
    int dp[n][4];
    mem(dp);
    return topDown(v, n, 0, dp, 0);
}




#include <iostream>
#include <vector>

using namespace std;

/* 
    내 방식
    Bottom Up 방식으로, 올라가면서 저장
 */
int Myvacation(vector<int> a, vector<int> b, vector<int> c){
    
    int TotalDays = a.size();

    vector<vector<int>> dp(TotalDays+1, vector<int>(3, 0));

    /* 
       N 번째 날에
       Act 번째 활동을 할 때
       나올 수 있는 최대 행복 값 
       => happy(N, Act)
       = max(happy(N-1, -- )) + 현재 Act 행복 값

       dp[N][Act] 에 그 최대 값을 저장해둔다
     */
    for (size_t day = 1; day <= TotalDays; day++)
    {
        for (size_t act = 0; act < 3; act++)
        {
            int prevMax{};
            vector<int>* up{};

            switch (act)
            {
            case 0:
                prevMax = max(dp[day-1][1], dp[day-1][2]);
                up = (&a);
                break;
            case 1:
                prevMax = max(dp[day-1][0], dp[day-1][2]);
                up = (&b);
                break;
            case 2:
                prevMax = max(dp[day-1][0], dp[day-1][1]);
                up = (&c);
                break;
            }

            dp[day][act] = prevMax + (*up)[day-1];            
        }
    }

    return max(dp[TotalDays][0], max(dp[TotalDays][1], dp[TotalDays][2]));
}


int main()
{
    vector<int> a{10, 20, 30};
    vector<int> b{40, 50, 60};
    vector<int> c{70, 80, 90};

    cout << Myvacation(a, b, c) << endl;
}