//Expected Time Complexity: O(logN)
//Hint: Binary Search


#include<bits/stdc++.h>
using namespace std;


int my_lowerBound(vector<int> A, int Val) {
    // your code goes here

    int lowerbound{ -1 };

    // 그냥 배열 전체를 한번 훑기
    for (auto x : A)
    {
        if (x <= Val) lowerbound = x;
        else break;
    }

    return lowerbound;
}


// sorted array => binary search 사용
int lowerBound(vector<int> A, int Val) {
    
    int sz = A.size();
    
    // 탐색하는 인덱스 => 양 끝에서 시작
    int l = 0, r = (sz-1);
    
    int answer = -1;
    

    // 언젠간 둘의 위치가 어긋나게 된다
    while (l <= r) {
        // 중간 위치 구하고
        int mid = (l + r) / 2;

        // l ~ mid 사이에 있는지 확인
        if (A[mid] > Val) {
            // r 위치 조정
            r = mid-1;
        }
        // mid <= < r 사이에 있을 때
        else {
            // 일단 mid 위치 = answer
            answer = A[mid];

            // l 위치 조정
            l = mid+1;
        }
    }
    
    return answer;
    
}