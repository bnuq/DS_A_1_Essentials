#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }


void my_rotate(vector<vector<int>>& matrix) {
      // your code goes here
      int n = matrix.size();
      int oldTmp{}, newTmp{};
      
      for(int i = 0; i < n/2; i++) {
          for(int j = i; j < n-1-i; j++) {
              int x{i}, y{j}, z{};
              oldTmp = matrix[x][y];
              
              for(int k = 0; k < 4; k++,x=y, y=z) {
                newTmp = matrix[y][n-1-x];
                matrix[y][n-1-x] = oldTmp;
                oldTmp = newTmp;
                z = n-1-x;
              }
              
          }
      }
      
}
