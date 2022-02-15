#include <iostream>
#include <vector>
using namespace std;

/* 2.
* 음수를 포함하는 임의의 배열, sub array sum 중 최대값을 구하고 싶다
* Expected Time Complexity: O(N), Hint: Kadane's Algorithm
*/
int my_maxSumSubarray(vector<int> A) {
    // 음수로만 이루어진 배열이 주어질 수 있다 => largest sum 이 음수가 될 수도 있다
    // 따라서 maximum sum 을 최소값으로 초기화 한다
    int curSum{ 0 }, maxSum{ INT_MIN };

    for (int i = 0; i < A.size(); i++)
    {
        // 현재 원소를 포함하는 구간 합을 구한다
        curSum += A[i];

        // 이전과는 다르게, maximum sum 이 음수일 수 있으므로 먼저 현재 구간 합과 현재까지 최대 합을 비교한다
        if (curSum > maxSum) maxSum = curSum;

        // 구간 합이 음수인 경우, 그 값이 최대 값이여도 앞으로 합을 구하는 데는 도움이 안된다
        // 그러니까 현재까지 합이 음수라면, 구간을 자르도록 한다
        // 다음번 요소 혼자서 구간을 이루도록 한다
        if (curSum < 0) curSum = 0;
    }

    return maxSum;
}
int another_maxSumSubarray(vector<int> A) {
    int maxSumFromPrevIndexToLeft = INT_MIN; // 이전구간의 합
    int finalAnswer = INT_MIN;               // 최종적으로 구하는 최대 합

    for (int i = 0; i < A.size(); i++) {
        // 이전 구간 합이 마이너스 => 이번 구간에 포함시킬 필요 없다
        if (maxSumFromPrevIndexToLeft < 0) {
            // 따라서 현재 값으로 새로운 구간을 만든다, 현재 위치를 시작 구간으로 재설정
            maxSumFromPrevIndexToLeft = A[i];
        }
        else {
            // 이전 구간 합이 플러스 였다면, 이번 요소 값에 상관없이 어쨌든 도움이 되는 요소
            // 이번 값을 더해 이전 구간에 포함시킨다
            maxSumFromPrevIndexToLeft += A[i];
        }
        // 최대 값과 비교, 최대 값 갱신
        finalAnswer = max(finalAnswer, maxSumFromPrevIndexToLeft);
    }
    return finalAnswer;
}

/*3.
* sorted array 가 주어질 때, 배열에서 어떤 Val 의 lower bound 값을 구하라
* If Val is not present in array, then lower bound of the Val means an integer which is just smaller than given integer
* Otherwise, Val itself is the answer
* binary search 를 활용하자
*/
int lowerBound(vector<int> A, int Val) {
    int sz = A.size();
    // 탐색 범위 => 인덱스로 표현
    int l = 0, r = (sz - 1);
    int answer = -1;
    
    // 범위를 점점 좁혀가기 때문에 => 언젠간 둘의 위치가 어긋나게 된다
    while (l <= r) {
        // 중간 위치를 구한다 => l ~ mid ~ r
        int mid = (l + r) / 2;

        // lower bound 가 l ~ mid 사이에 있는지 확인
        if (A[mid] > Val) { // non-decreasing 으로 정렬됐다 가정하기 떄문에
            // r 위치 조정
            r = mid - 1;
        }
        // mid <= < r 사이에 있을 때
        else {
            // lower bound => 일단 Val 보다 작으므로 가능성이 존재한다
            // 일단 mid 위치 = answer
            answer = A[mid];
            // 새로운 구간을 다시 조사
            l = mid + 1;
        }
    }
    return answer;
}

/*
* sorted array 가 주어짐, 배열 요소들 중, 그 합이 x 와 가장 가까운 pair 를 찾아라
*/
pair<int, int> closestSum(vector<int> arr, int x) {
    // 정답인 배열 인덱스를 저장하는 변수
    int res_l, res_r;
    int n = arr.size();

    // 검색 범위를 나타내는 인덱스, 배열의 맨 왼쪽과 오른쪽을 가리킴, 서서히 범위를 좁힌다
    // 배열이 이미 정렬되어 있다는 점을 이용 => 합이 x 에 가까워지게 하기 위해서 더 큰 값을 더하거나 더 작은 값을 더하게 한다
    int l = 0, r = n - 1, diff = INT_MAX;

    // 둘이 어긋날 떄까지 반복
    while (r > l) {
        // 합 - 차 가 최소가 될때
        if (abs(arr[l] + arr[r] - x) < diff) {
            // 정보 갱신
            res_l = l;
            res_r = r;
            diff = abs(arr[l] + arr[r] - x);
        }
        // 합이 크다면 줄여야 하니까, 큰 쪽을 옮긴다
        if (arr[l] + arr[r] > x)
            r--;
        // 작다면 작은 쪽을 옮긴다
        else l++;
    }
    // 이걸로 pair 를 만들 수 있다 ~ 신기
    return { arr[res_l], arr[res_r] };
}