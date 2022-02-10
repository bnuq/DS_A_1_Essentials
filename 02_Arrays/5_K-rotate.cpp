//Expected Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

vector<int> my_kRotate(vector<int> a, int k) {
    // your code  goes here
    vector<int> b;
    b.resize(a.size()); // �Ȱ��� ũ���� ���͸� �����

    for (int i = 0; i < a.size(); i++)
    {
        // �̵� �� �� �ε��� ���
        int index = (i + k) % (a.size());
        b[index] = a[i];
    }

    return b;
}



vector<int> kRotate(vector<int> a, int k)
{
    vector<int> v;
    int n = a.size();
    k = k % n; // ������ �ϴ� �Ÿ��� �̸� ���
 

    // ���� �迭����, ���� �� �迭�� ���� �ű��, ������� �ִ´�
    // �̰� �ʹ� ������ �� ������?
    // �� �������� �˰ڴµ�, �̰� �³�?
    for(int i = 0; i < n; i++)
    {
       // k ���� ������ ���ƿ��� �ȴ�
       // �ѹ��� ���Ƽ�, ������ �� �ֵ�
       if(i < k)
       {
           v.push_back(a[n + i - k]);
       }
       // �� ���� ���� �ʰ�, �迭 ������ �����̴� �ֵ�
       // 0, 1, 2, 3 ... �� �ش�
       else
       {
           v.push_back(a[i - k]);
       }
    }
    return v;
}



