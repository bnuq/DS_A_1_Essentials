#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    // your code goes here
    vector<int> r,c;
    int n = arr.size(), m = arr[0].size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0){
                r.push_back(i); c.push_back(j);
            }
        }
    }
    
    for(auto x : r){
        for(int i=0; i<n; i++){
            arr[x][i] = 0;
        }
    }
    for(auto x : c){
        for(int i=0; i<n; i++){
            arr[i][x] = 0;
        }
    }
    
    return arr;
}



vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    // your code goes here
    vector<pair<int, int>> points{};
    
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            if(arr[i][j] == 0) points.emplace_back(i,j);
        }
    }
    
    sort(points.begin(), points.end());
    
    for(const auto& e : points) {
        for(int row = 0; row < arr.size(); row++)
            arr[row][e.second] = 0;
            
        for(int col = 0; col < arr[e.first].size(); col++)
            arr[e.first][col] = 0;
    }
    
    return arr;
}