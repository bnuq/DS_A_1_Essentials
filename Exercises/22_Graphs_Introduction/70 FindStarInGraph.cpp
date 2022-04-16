#include <vector>
using namespace std;


// 기존 정답 뭔가 이상하다
int MyfindCenter(vector<vector<int>>& v) {
    
    int NumOfNodes = v.size() + 1;
    
    vector<vector<int>> adjList(NumOfNodes + 1, vector<int>{});

    for (const auto& edge : v) {
        int v1 = edge[0];
        int v2 = edge[1];

        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }


    for (int i = 0; i < adjList.size(); i++) {
        if (adjList[i].size() == NumOfNodes - 1) {
            return i;
        }
    }

    return -1;
}