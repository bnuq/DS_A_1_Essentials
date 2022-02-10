//Expected Time Complexity: O(N)
//Hint: Two Pointer Approach

#include<bits/stdc++.h>
using namespace std;


pair<int, int> my_closestSum(vector<int> arr, int x) {
    // your code goes here
    int f{ 0 }, s{ 0 }, diff{ INT_MAX };


    // 2�� ����, ��� �������� ����
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int sum = arr[i] + arr[j]; // �� �����ֿ� ���� ���� ���ϰ�
            if (abs(x - sum) < diff) // �� �հ� x ���� ���̰� ���� ���� ���� ã�´�
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
    
    // �迭 �ε����� �����ϴ� ����
    int res_l, res_r;

    int n = arr.size();

    // �迭�� ���� ������ ���� => �迭�� �̹� ���ĵǾ� �����ϱ� ����? => �̹� ���ĵǾ� �ִٴ� ���� �̿�..
    int l = 0, r = n-1, diff = INT_MAX;
 
    // ���� ��߳� ������ �ݺ�
    while (r > l)
    {
       // �� - �� �� �ּҰ� �ɶ�
       if (abs(arr[l] + arr[r] - x) < diff)
       {
           res_l = l;
           res_r = r;
           diff = abs(arr[l] + arr[r] - x);
       }
 
       // ���� ũ�ٸ� �ٿ��� �ϴϱ�, ū ���� �ű��
       if (arr[l] + arr[r] > x)
           r--;
       
       // �۴ٸ� ���� ���� �ű��
       else 
           l++;
    }
    

    // �̰ɷ� pair �� ���� �� �־�?
    return {arr[res_l], arr[res_r]};
}