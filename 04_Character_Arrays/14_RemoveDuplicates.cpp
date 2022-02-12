Expected Time Complexity : O(N)


#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    // your code goes here

    // set 에 넣는다 => binary tree 구조, 중복 keys 는 허용하지 않는다
    // iterator 방식으로 vector => set 에 넣는구나
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