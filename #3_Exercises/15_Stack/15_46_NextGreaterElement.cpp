

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr){
    int n = arr.size();
    vector<int> arr1(n, 0);
    stack<int> s;
 
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
 
        if (s.empty())
            arr1[i] = -1;        
        else
            arr1[i] = s.top();       
 
        s.push(arr[i]);
    }
        
    return arr1;
}
    
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> v) {
    vector<int> res{};

    for (int i = 0; i < v.size(); i++) {
        stack<int> s{};
        bool findV{ false };

        for (int j = v.size() - 1; j > i; j--) {
            s.push(v[j]);
        }

        while (!s.empty()) {
            if (s.top() > v[i]) {
                res.push_back(s.top());
                findV = true;
                break;
            }
            else s.pop();
        }

        if (!findV) res.push_back(-1);
    }

    return res;
}