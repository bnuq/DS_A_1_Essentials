#include <iostream>
#include <vector>

using namespace std;


// Top Down dp code
/* 
    y 년 째에 L ~ R 구간 내의 와인을 팔때, 최대값을 구한다
    L~R 구간 에서 판매할 수 있는 최대 가격을 dp[L][R] 에 저장한다
        몇 년째 인지는 저장안하나?
        어차피 해당 구간이 정해지려면 => 반드시 몇 개가 빠져야 하고
        그러면 년도가 반드시 정해진다
        dp 배열에서 대각선 방향으로, 년도가 동일하다

        예를 들어 dp[1][1] => 1+1 = 2번째 와인만 남아서 팔 때 최대값
        2번째 와인만 남아야 하니까, 반드시 앞의 4개의 와인이 팔리고 난 뒤
        = 5년차 
        => 0,0 1,1 2,2 ... 모두 5년차 때 최대 값이라는 걸 알 수 있다

    dp 배열에 저장할 때 중요한 건 결국 구간
 */

int wines(int dp[][10], int prices[], int L, int R, int y)
{
    // base case
    if(L > R) return 0; // 계산 구간을 벗어남

    // need if a state is ready, 계산 완료된 값인 경우
    if(dp[L][R] != 0) return dp[L][R];

    // recursive case
    // 이번 년도에 가장 왼쪽 와인을 팔았을 경우, 최대 가격
    int pick_left = y * prices[L] + wines(dp, prices, L+1, R, y+1);

    // 이번 년도에 가장 오른쪽 와인을 팔았을 경우, 최대 가격
    int pick_right = y * prices[R] + wines(dp, prices, L, R-1, y+1);

    
    // dp 에 저장하면서, 값 리턴
    return dp[L][R] = max(pick_left, pick_right);
}


// Bottom UP
/* 
    반대로 n 년 후, 하나의 원소만 남은 경우부터 최대 가격을 채워나가자

        dp 배열을 대각선으로 채워나간다
    +   미래 상황 => 현재 상황 순서로 값을 채운다
 */

int wines_bottom_up(const vector<int>& prices) // 가격 정보, 계산 하려는 년도
{
    int NumOfWines = prices.size();

    // 밑에서부터 결과를 저장해 나갈, dp 배열 준비
    vector<vector<int>> dp(NumOfWines, vector<int>(NumOfWines, 0));

    /* 
        대각선부터, 우측 상단 위치로 값을 채우려면
        
        row => 낮은 데 -> 높은 곳으로 올라가야 하고
        col => 왼쪽 -> 오른쪽 으로 채우는데
            => col 값이 row 보다 작으면, 대각선 좌측 하단 영역
                채울 필요가 없다
     */
    for(int row = NumOfWines - 1; row >= 0; row--) {
        for(int col = 0; col < NumOfWines; col++) {

            if(col < row) dp[row][col] = 0;
            
            else if(col == row) {

                // dp 배열의 대각선의 경우
                // bottom up 을 시작하는 가장 밑바닥
                dp[row][col] = NumOfWines * prices[row];
            }

            else // col > row
            {
                // 대각선 + 우측 상단 영역

                // 해당 칸 구간의 년도
                int year = NumOfWines - (col - row);

                /* 
                    현재 구하고자 하는 것
                    row ~ col 구간에서 나오는 최대 값
                 */
                // row 번째를 이번에 팔았을 때
                int pick_left = prices[row] * year + dp[row+1][col];

                // col 번째를 팔았을 때 이익
                int pick_right = prices[col] * year + dp[row][col-1];


                dp[row][col] = max(pick_left, pick_right);
            }

        }
    }

    for(auto r : dp) {
        for(auto c : r) 
            cout << c << ", ";
        
        cout << endl;
    }
    cout << endl;

    return dp[0][NumOfWines-1];
}



int main()
{
    vector<int> WinePrices{
        2, 3, 5, 1, 4, 6, 1, 4
    };

    cout << wines_bottom_up(WinePrices) << endl;

}