//Hint: Pre Compute Cumilative Sums of every index i,j.

// Expected Time Complexity:
// Pre Computing : O(N^2) => (0,0) ~ (n,m) ������ ��� ���ҵ��� ��, prefix sum �� ���� ����Ѵ�
// Queries: O(1)

#include <iostream>
#include <vector>
using namespace std;


// �ڵ带 �� �˾� �԰ڴµ�?
int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){
    int m=v.size();
    int n=v[0].size();
    // // int aux[m][n];
    int M=m;
    int N=n;

    // ���� ���͸� �׳� ���� => ������ ���߱� �������ϱ� �׳� �̷��� �ع���
    // �׷� ��������� �Ȱ��� ���� ����
    vector<vector<int>> aux = v;
    vector<vector<int>> mat = v;
    int tli=sr, tlj=sc, rbi=er, rbj=ec;
    
    
    // ù��° row ����
    for (int i=0; i<N; i++)
      aux[0][i] = mat[0][i];
  
    // �� ���� �Ʒ��� ����
    // Do column wise sum
    for (int i=1; i<M; i++)
      for (int j=0; j<N; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];
  

    // ���ʿ��� ���������� �ջ�
    // Do row wise sum
    for (int i=0; i<M; i++)
        for (int j=1; j<N; j++)
            aux[i][j] += aux[i][j-1];
 
 
    int res = aux[rbi][rbj];
  
    // Remove elements between (0, 0) and (tli-1, rbj)
    if (tli > 0)
       res = res - aux[tli-1][rbj];
  
    // Remove elements between (0, 0) and (rbi, tlj-1)
    if (tlj > 0)
       res = res - aux[rbi][tlj-1];
  
    // Add aux[tli-1][tlj-1] as elements between (0, 0)
    // and (tli-1, tlj-1) are subtracted twice
    if (tli > 0 && tlj > 0)
       res = res + aux[tli-1][tlj-1];
  

    for (auto x : aux) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }


    return res;
}



int my_sum(vector<vector<int>> v, int sr, int sc, int er, int ec) {
    // your code goes here

    // 2D prefix sum array ����� ����
    vector<vector<int>> res{};

    for (int row = 0; row < v.size(); row++) {
        vector<int> rowVec{};
        for (int col = 0; col < v[row].size(); col++) {
            if (row == 0) {
                if (col == 0) rowVec.push_back(v[0][0]);
                else rowVec.push_back(rowVec[col - 1] + v[0][col]);
            }
            else {
                if (col == 0) rowVec.push_back(res[row - 1][0] + v[row][0]);
                else rowVec.push_back(res[row-1][col] + rowVec[col - 1] - res[row-1][col-1] + v[row][col]);
            }
        }
        res.push_back(rowVec);
    }

    for (auto x : res) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }



    int part4 = res[er][ec];
    int part3 = (sr == 0) ? 0 : res[sr - 1][ec];
    int part2 = (sc == 0) ? 0 : res[er][sc - 1];
    int part1 = (sr == 0 or sc == 0) ? 0 : res[sr - 1][sc - 1];
    return part4 - part3 - part2 + part1;
}


void getPrefixArray(vector<vector<int>> v) {
    /*
        2D prefix sum array ����� ���
        1 1+2
        1+3 2+4+1+3

        1 2+1
        3+1 4+3+2+1

        ���� / ���� �������� prefix sum �� ���� ����
        ���� / ���� �������� prefix sum �� ���ϸ� �ȴ�

        ���� ������, �ǹ̸� �����ϸ鼭 �ǹ̸� �����ϰ�, �ߺ��� ������ ����... ���� �ʾƵ� �ȴ�
    */
    // �־��� ���Ϳ� ���� ũ��� ���� => reserve, resize ���ʿ�
    vector<vector<int>> prefixSum = v;

    
    // ���� ù��° column �� �����ؿ´�
    for (int row = 0; row < prefixSum.size(); row++) {
        prefixSum[row][0] = v[row][0];
    }

    // �� ����, column ���� prefix sum �� ���Ѵ�
    for (int col = 1; col < prefixSum[0].size(); col++) {
        for (int row = 0; row < prefixSum.size(); row++) {
            prefixSum[row][col] = prefixSum[row][col - 1] + v[row][col];
        }
    }

    
    // column's prefix sum ���� row ���� prefix sum �� ���Ѵ� => ��ü 2D prefix sum array �� ��� �ȴ�
    for (int row = 1; row < prefixSum.size(); row++) {
        for (int col = 0; col < prefixSum[row].size(); col++) {
            prefixSum[row][col] += prefixSum[row - 1][col];
        }
    }

    for (auto x : prefixSum) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}



int main() {
    vector<vector<int>> mat{ {1,2,3,4,6},
        {5,3,8,1,2},
        {4,6,7,5,5},
        {2,4,8,9,4} };

    //cout << sum(mat, 0, 0, 1, 1) << endl;
    getPrefixArray(mat);
}


