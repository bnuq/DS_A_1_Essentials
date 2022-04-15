#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    priority_queue<int> q;

    for (int i = 0; i < nums.size(); i++) {
        //애초에 Heap 에 넣을 때, 원하는 연산을 한 채로 넣는다
        q.push((nums[i] - 1));
    }

    int p = q.top(); //첫번째 max
    q.pop();
    return p * q.top(); //두번째 max 를 구해서 첫번째와 곱한다
}