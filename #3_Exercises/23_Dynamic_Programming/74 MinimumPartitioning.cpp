#include <bits/stdc++.h>
using namespace std;


/* 
    주어진 배열을 2개의 부분집합으로 나누어서
    둘의 차이가 가장 적게 날 때, 그 가장 적게나는 차이값을 구하고 싶다
 */
int findMin(vector<int> arr)
{
    // 배열 크기
    int n = arr.size();
    int sum = 0; // 원소들의 총 합
    for (int i = 0; i < n; i++)
        sum += arr[i];
  

    /* 
        Create an array to store results of subproblems
        
        배열의 첫 번째, 0번째를 시작점으로 고정
        N 번째 까지의 범위 내에서
        만들 수 있는 모든 subsets 에 대해서
        합을 만들 수 있는 자리에 true 를 저장한다

        dp[N][s] = true
            0~N 인덱스 범위 내에서 만들 수 있는 부분집합들 중에서
            요소의 합이 s 인 경우가 존재한다
     */
    bool dp[n + 1][sum + 1];
  
    
    // Initialize first column as true. 0 sum is possible with all elements.
    // 합이 0 인 공집한은 언제나 만들 수 있다
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
  
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    // index = 0 -> 요소가 아예 없는 것을 의미 => 0 이 아닌 합을 만들 수 없다
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
  


    // Fill the partition table in bottom up manner
    // 배열의 범위를 점차 늘려나가면서, 만들 수 있는 합의 종류를 찾아 넓힌다
    for (int i = 1; i <= n; i++) {          // 배열 범위 증가
        for (int j = 1; j <= sum; j++) {    // 만들 수 있는 sum 확인
            
            // If i'th element is excluded
            // 추가된 범위인 i 번째 요소가 합을 구하는 데 쓰이지 않은 경우
            // 기존에 만들 수 있던 합들을 똑같이 만들 수 있다
            dp[i][j] = dp[i - 1][j];
  

            // If i'th element is included
            // i 번째 요소를 추가해서 합을 만드는 경우
            /* 
                i 번째 요소 = arr[i-1]
                j => 이번에 만들고자 하는 값

                만들려고 하는 값보가, 더하는 값이 클수는 없으니까
                일단 작은 걸 확인하고
             */
            if (arr[i - 1] <= j)
                /* 
                    |= , or 연산자
                        연산 대상에서 true 가 하나라도 있으면
                        true 가 된다
                    
                    이전 n-1 범위에서 j-arr[i-1] 값을 만들 수 있는 지 여부를
                    그대로 이번 dp[i][j] 에 넣는다
                */
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
  



    // Initialize difference of two sums.
    int diff = INT_MAX;
  
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    // 결국 원하는 범위는 전체 배열에서 만들 수 있는 부분집합이 대상이므로
    // 마지막 row 인 index n 부분이다
    // 해당 부분만 조사
    for (int j = sum / 2; j >= 0; j--) { // sum 의 절반 부분에서 부터 검색
        // Find the
        if (dp[n][j] == true) { // 값이 true, 만들 수 있는 sum 이라 판단되는 곳에서
            diff = sum - 2 * j; // 빼고
            break;              // 바로 탈출
        }
    }
    
    return diff;
}