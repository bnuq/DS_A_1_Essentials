#include<bits/stdc++.h>
using namespace std;


// �ش䵵 function call stack �� ���ؼ� bfs ����
                                                                // ��δ� �׳� �� ���縦 ���� ���� => �ְ� ���� �� �ʿ䰡 ����..!
void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> path, int src, int dst) {

    // src ��� �湮
    path.push_back(src);


    if(src == dst) {
        result.push_back(path);
        return;
    }

    /*
        DAG ���� => Directed Acyclic Graph

        ����Ŭ�� �׷��� ���� �������� �ʴ´�
        �ƹ��� ���� ����Ŭ�� �������� �ʴ´�

        ���� �Դ� ���� �ٽ� ���ư��� ��찡 ���� �������� �ʴ´�
        ���� �湮 ���θ� ����� �ʿ䰡 ����...
    */
    for(auto node : graph[src])
        // �׳� �̿��� �ٷ� Ȯ���ϸ� �ȴ�...
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

    // curNode �� �湮
    route.push_back(curNode);
    visit[curNode] = true;

    // base => �����ߴ�
    if (curNode == dest) {
        res.push_back(route);
        return;
    }

    // �������� ���ߴٸ� �̿� ���� �߿���
    for (auto nbr : graph[curNode]) {
        // ���� �湮���� �ʴ� ��忡 ���ؼ���
        if (visit[nbr] == false) {
            // BFS, �湮�� �Ѵ�
            BFShelper(graph, res, route, nbr, dest, visit);

            // �湮�� ��������, �ش� ��带 ��Ͽ��� �����, ���� �̿� ���� �Ѿ��
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