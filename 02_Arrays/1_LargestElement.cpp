//Expected Time Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

int my_largestElement(vector<int> arr) {
    int largest{ arr[0] }; // 배열 첫 번째 값을 최소 값으로 먼저 설정

    for (size_t i = 1; i < arr.size(); i++)
        // 돌면서 확인
        largest = (arr[i] > largest) ? arr[i] : largest;

    return largest;

}

int largestElement(vector<int> A) {
    
     // 실제 최소값으로 초기화
     int largestEle = INT_MIN;
     
     // 간단하게 max 함수 사용
     for (auto element : A ) {
         largestEle = max(largestEle, element);
     }
     
     return largestEle;
}