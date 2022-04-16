#include<bits/stdc++.h>
using namespace std;


// 해답도 function call stack 을 통해서 bfs 구현
                                                                // 경로는 그냥 값 복사를 통해 전달 => 넣고 빼고 할 필요가 없다..!
void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> path, int src, int dst) {

    // src 노드 방문
    path.push_back(src);


    if(src == dst) {
        result.push_back(path);
        return;
    }

    /*
        DAG 가정 => Directed Acyclic Graph

        사이클이 그래프 내에 존재하지 않는다
        아무리 작은 사이클도 존재하지 않는다

        따라서 왔던 노드로 다시 돌아가는 경우가 절대 존재하지 않는다
        따라서 방문 여부를 기록할 필요가 없다...
    */
    for(auto node : graph[src])
        // 그냥 이웃을 바로 확인하면 된다...
        dfs(graph, result, path, node, dst);
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> paths; vector<int> path;
    int nodes = graph.size();
    if(nodes == 0) return paths;
    dfs(graph, paths, path, 0, nodes - 1);
    return paths;
}




void BFShelper(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& route, int curNode, int dest, vector<bool>& visit) {

    // curNode 에 방문
    route.push_back(curNode);
    visit[curNode] = true;

    // base => 도착했다
    if (curNode == dest) {
        res.push_back(route);
        return;
    }

    // 도착하지 못했다면 이웃 노드들 중에서
    for (auto nbr : graph[curNode]) {
        // 아직 방문하지 않는 노드에 대해서만
        if (visit[nbr] == false) {
            // BFS, 방문을 한다
            BFShelper(graph, res, route, nbr, dest, visit);

            // 방문이 끝났으면, 해당 노드를 기록에서 지우고, 다음 이웃 노드로 넘어간다
            route.pop_back();
            visit[nbr] = false;
        }
    }
}

vector<vector<int>> MyallPathsSourceTarget(vector<vector<int>>& graph) {

    int numOfNode = graph.size();

    vector<bool> visited(numOfNode, false);
    vector<vector<int>> res{};
    vector<int> route{};

    BFShelper(graph, res, route, 0, numOfNode - 1, visited);

    return res;
}