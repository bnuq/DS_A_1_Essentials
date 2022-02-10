//Expected Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

vector<int> my_kRotate(vector<int> a, int k) {
    // your code  goes here
    vector<int> b;
    b.resize(a.size()); // 똑같은 크기의 벡터를 만들고

    for (int i = 0; i < a.size(); i++)
    {
        // 이동 후 들어갈 인덱스 계산
        int index = (i + k) % (a.size());
        b[index] = a[i];
    }

    return b;
}



vector<int> kRotate(vector<int> a, int k)
{
    vector<int> v;
    int n = a.size();
    k = k % n; // 돌고자 하는 거리를 미리 계산
 

    // 기존 배열에서, 돌린 후 배열로 값을 옮긴다, 순서대로 넣는다
    // 이건 너무 복잡한 거 같은데?
    // 뭔 말인지는 알겠는데, 이게 맞나?
    for(int i = 0; i < n; i++)
    {
       // k 개가 앞으로 돌아오게 된다
       // 한바퀴 돌아서, 앞으로 올 애들
       if(i < k)
       {
           v.push_back(a[n + i - k]);
       }
       // 한 바퀴 돌지 않고, 배열 내에서 움직이는 애들
       // 0, 1, 2, 3 ... 에 해당
       else
       {
           v.push_back(a[i - k]);
       }
    }
    return v;
}



