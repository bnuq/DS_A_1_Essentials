#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a, pair<int, int> b){
    float x = sqrt((a.first*a.first) + (a.second*a.second));
    float y = sqrt((b.first*b.first) + (b.second*b.second));
    return x < y;
}

vector<pair<int,int>> sortCabs(vector<pair<int,int>> v){
    // your code  goes here
    sort(v.begin(), v.end(), comp);
    return v;
}

#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> sortCabs(vector<pair<int, int>> v) {
    // your code  goes here
    sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {
        return e1.first * e1.first + e1.second * e1.second < e2.first* e2.first + e2.second * e2.second;
        });

    return v;
}