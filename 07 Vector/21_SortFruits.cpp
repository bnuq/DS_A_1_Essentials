#include<bits/stdc++.h>
using namespace std;

bool comp(pair<string,int> a, pair<string, int> b){
    return a.second < b.second;
}

vector<pair<string,int>> sortFruits(vector<pair<string,int>> v, string S){
    // your code  goes here
    if(S=="name") sort(v.begin(), v.end());
    else sort(v.begin(), v.end(), comp);
    return v;
}

vector<pair<string,int>> sortFruits(vector<pair<string,int>> v, string S){
    // your code  goes here
    sort(v.begin(), v.end(), [S](const auto& e1, const auto& e2){
        if(S == "name") 
            return e1.first < e2.first;
        else if(S == "price")
            return e1.second < e2.second;
    });
    
    return v;
}