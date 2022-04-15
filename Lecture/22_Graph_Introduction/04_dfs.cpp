#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}
	void dfsHelper(int node,bool *visited){
		// 해당 노드에 방문함을 기록
		visited[node] = true;

		// 방문한 노드에서 어떤 작업을 하고
		cout << node << ",";

		// make a dfs call on all its unvisited neighbours
		// Recursive Call => Stack 과 유사
		// 나중에 넣은 노드먼저 방문한다 => 먼저 깊게 탐색
		for(int nbr : l[node]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
		return;
	}

	// DFS Graph Traversal
	void dfs(int source){
		// 방문 여부를 저장하는 리소스를 할당
		bool *visited = new bool[V]{0};

		// source 노드부터 시작
		dfsHelper(source,visited);
	}
};

int main(){
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.dfs(1);
	return 0;
}