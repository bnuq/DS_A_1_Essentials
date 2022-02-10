//Expected Time Complexity: O(N)
//Hint: Kadane's Algorithm


#include<bits/stdc++.h>
using namespace std;


int my_maxSumSubarray(vector<int> A) {
    // sum 이 음수가 될 수 있기 때문에, 최소값으로 초기화 한다
    int curSum{ 0 }, maxSum{ INT_MIN };

    for (int i = 0; i < A.size(); i++)
    {
        // i 번쨰까지 구간 합을 구하고
        curSum += A[i];

        // 더한 결과를 먼저 확인한다 => 최대값이 되는 지?
        if (curSum > maxSum) maxSum = curSum;

        // 구간 합이 음수인 경우, 그 값이 최대 값이여도 앞으로 합을 구하는 데는 도움이 안된다
        // 그러니까 음수라면, 구간을 자르고 다시 시작하도록 한다
        if (curSum < 0) curSum = 0;
    }

    return maxSum;
}


int maxSumSubarray(vector<int> A) {
    

    bool f =true;
    int rr=INT_MIN;


    // 전체 구간 확인
    for(auto x : A){
        if(x >0 ) f = false; // 양수가 하나라도 있는 지 확인
        if(x > rr) rr = x;   // 최대값
    }
    // 모두 음수라면, 최대값을 리턴 => 그게 max sum
    if(f) return rr;
    

    // 배열의 모든 요소가 음수는 아니라는 걸 확인한 후,

    int maxSumFromPrevIndexToLeft = 0;
    
    int finalAnswer = 0;
    
    int temporary  = 0;
    
    int arraySize = A.size();
    for (int i = 0; i < arraySize; i++) {

        // 구간 합 = 이전 합 + 현재 값
        temporary = maxSumFromPrevIndexToLeft + A[i];

        // 구간 합이, 현재 값보다 더 작다 => 이전 합이 마이너스다? 그게 말이돼? => 이전 합이 도움이 안된다
        // 어쨌든 현재 하나의 값보다 더한 값이 더 작다면, 계속 더할 필요가 없다
        if (temporary < A[i]) {
            // 현재 값만 사용한다, 현재 위치를 시작 구간으로 재설정
            maxSumFromPrevIndexToLeft = A[i];
        }
        else {
            // 구간 핪으로 갱신
            maxSumFromPrevIndexToLeft = temporary;
        }
        // 최대 값과 비교, 최대 값 갱신
        finalAnswer = max(finalAnswer, maxSumFromPrevIndexToLeft);
    }
    
    return finalAnswer;
    
}


// 주어진 해답에서, 음수로만 이루어진 배열을 거르지 않고 한번에 다 처리하는 방법
int another_maxSumSubarray(vector<int> A) {
    
    // 큰 값이 오면 바꾸어야 하므로 최소 값을 넣는다
    int maxSumFromPrevIndexToLeft = INT_MIN;
    int finalAnswer = INT_MIN;

    int arraySize = A.size();
    for (int i = 0; i < arraySize; i++) {

        // 이전이 마이너스 => 확실히 더할 필요가 없다 => 현재 값만 구간에 포함
        if (maxSumFromPrevIndexToLeft < 0) {
            // 현재 값만 사용한다, 현재 위치를 시작 구간으로 재설정
            maxSumFromPrevIndexToLeft = A[i];
        }
        else {
            // 값이 늘어날수도 있고
            // 값이 줄어들더라도 그 다음에 증가할 수 있으니
            // 일단 더한다
            maxSumFromPrevIndexToLeft += A[i];
        }
        // 최대 값과 비교, 최대 값 갱신
        finalAnswer = max(finalAnswer, maxSumFromPrevIndexToLeft);
    }

    return finalAnswer;
}