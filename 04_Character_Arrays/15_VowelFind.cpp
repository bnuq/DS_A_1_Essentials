Expected Time Complexity : O(N)


#include<bits/stdc++.h>
using namespace std;

string vowel(string S){
    // your code goes here
    string out;
    for(auto x : S){
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') out.push_back(x);
    }
    return out;
} 


string my_vowel(string S) {
    // your code goes here
    string res{};


    // for_each 알고리즘 한번 사용해 봤음
    for_each(S.begin(), S.end(), [&res](const auto& e) {
        if (e == 'a' or e == 'e' or e == 'i' or e == 'o' or e == 'u')
            res += e;
        });

    return res;

}