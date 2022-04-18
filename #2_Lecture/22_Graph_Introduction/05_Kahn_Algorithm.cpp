#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {

	int V;
	list<int>* l;

public:
	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}
	// Topological Sorting => edge 에 반드시 방향이 있어야 한다
	void addEdge(int u, int v) {
		l[u].push_back(v);
	}

	// Topological sorting :: Kahn's Alogirhtm 구현
	void kahnAlgorithm() {
		
		// dependency num 을 저장
		vector<int> indegree(V, 0);

		// Iterate over all the edges to find the right indegree
		for (int i = 0; i < V; i++) {
			// 어떤 노드로 부터 도착점으로 지정되어 있는 노드가 있으면
			// indegree 개수를 증가시킨다
			for (auto nbr : l[i])
				indegree[nbr]++;
		}


		// BFS
		queue<int> q{};
		// Init the q with nodes having 0 indegree
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) q.push(i);
		}

		// Start popping
		while (!q.empty()) {
			int node = q.front();
			cout << node << " , ";
			q.pop();

			// Iterate over the nbrs of this node
			// and reduce their indegree by 1
			for (auto nbr : l[node]) {
				indegree[nbr]--;

				// 0 이 되면 큐에 넣는다
				if (indegree[nbr] == 0) q.push(nbr);
			}
		}
	}
};



int main() {

	Graph g(6);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(1, 4);
	g.addEdge(1, 2);

	g.kahnAlgorithm();

	return 0;
}