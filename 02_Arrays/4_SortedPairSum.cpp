//Expected Time Complexity: O(N)
//Hint: Two Pointer Approach

#include<bits/stdc++.h>
using namespace std;


pair<int, int> my_closestSum(vector<int> arr, int x) {
    // your code goes here
    int f{ 0 }, s{ 0 }, diff{ INT_MAX };


    // 2중 루프, 모든 순서쌍을 조사
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int sum = arr[i] + arr[j]; // 각 순서쌍에 의한 합을 구하고
            if (abs(x - sum) < diff) // 그 합과 x 사이 차이가 가장 작을 떄를 찾는다
            {
                f = arr[i];
                s = arr[j];
                diff = abs(x - sum);
            }
        }
    }

    return make_pair(f, s);
}



// sorted array
pair<int, int> closestSum(vector<int> arr, int x){
    
    // 배열 인덱스를 저장하는 변수
    int res_l, res_r;

    int n = arr.size();

    // 배열의 끝과 끝에서 시작 => 배열이 이미 정렬되어 있으니까 가능? => 이미 정렬되어 있다는 것을 이용..
    int l = 0, r = n-1, diff = INT_MAX;
 
    // 둘이 어긋날 떄까지 반복
    while (r > l)
    {
       // 합 - 차 가 최소가 될때
       if (abs(arr[l] + arr[r] - x) < diff)
       {
           res_l = l;
           res_r = r;
           diff = abs(arr[l] + arr[r] - x);
       }
 
       // 합이 크다면 줄여야 하니까, 큰 쪽을 옮긴다
       if (arr[l] + arr[r] > x)
           r--;
       
       // 작다면 작은 쪽을 옮긴다
       else 
           l++;
    }
    

    // 이걸로 pair 를 만들 수 있어?
    return {arr[res_l], arr[res_r]};
}