#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    priority_queue<int> q;

    for (int i = 0; i < nums.size(); i++) {
        //���ʿ� Heap �� ���� ��, ���ϴ� ������ �� ä�� �ִ´�
        q.push((nums[i] - 1));
    }

    int p = q.top(); //ù��° max
    q.pop();
    return p * q.top(); //�ι�° max �� ���ؼ� ù��°�� ���Ѵ�
}