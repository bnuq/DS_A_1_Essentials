#include<bits/stdc++.h>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> arr){
    // your code  goes here
    int i, j, n=arr.size();

    
    // 한 번이라도 swap 이 일어났는 지 아닌 지 체크하는 함수
    bool swapped{ false };

    // 처음 ~ 끝 훑는 회수 => 총 n-1 번 바퀴 돈다
    for (i = 0; i < n-1; i++)
    {

        // 첫 바퀴 때 이미 정렬이 된 상태인지 아닌지를 확인할 수 있다
        // swapped = false;

        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);

                // swap 발생
                swapped = true;
            }
        }
 
        // IF no two elements were swapped by inner loop, then break
        // 첫 번째 바퀴때만 확인하면 된다
        if (i == 0 && swapped == false) break;
    }
   
   return arr;
}