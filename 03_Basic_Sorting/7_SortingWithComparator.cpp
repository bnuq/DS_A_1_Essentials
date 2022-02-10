#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
    return a > b;
}
vector<int> sortingWithComparator(vector<int> v, bool flag){
    // your code  goes here
    if(flag) sort(v.begin(), v.end()); // 기본을 이용
    else sort(v.begin(), v.end(), compare);
    return v;
}


vector<int> my_sortingWithComparator(vector<int> a, bool flag) {
    // your code  goes here

    auto f1 = [](const auto& e1, const auto& e2) {
        return e1 < e2;
    };

    auto f2 = [](const auto& e1, const auto& e2) {
        return e1 > e2;
    };

    if (flag) sort(a.begin(), a.end(), f1);
    else sort(a.begin(), a.end(), f2);


    return a;
}