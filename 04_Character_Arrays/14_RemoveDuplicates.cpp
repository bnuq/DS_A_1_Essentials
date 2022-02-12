Expected Time Complexity : O(N)


#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    // your code goes here

    // set �� �ִ´� => binary tree ����, �ߺ� keys �� ������� �ʴ´�
    // iterator ������� vector => set �� �ִ±���
    set<char> ss(s.begin(), s.end());
    string str;
 
    for (auto x : ss)
       str.push_back(x);
 
    return str;
}


string my_removeDuplicate(string s) {
    // your code goes here
    string res{};

    sort(s.begin(), s.end());

    for (auto itr = s.begin(); itr < s.end(); itr++) {
        if (*itr == *(itr + 1)) continue;
        else {
            res += *itr;
        }
    }

    return res;

}