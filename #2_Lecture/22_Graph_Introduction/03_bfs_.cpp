#include<iostream>
#include<list>
#include<queue>
using namespace std;


// 기존 Adjacency list Graph 코드
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


	// 해당 그래프를 Traversal 하는 메서드
	// BFS Graph Traversal
	void bfs(int source){

		queue<int> q; // Traversal 하며 이웃을 저장할 큐
		bool *visited = new bool[V]{0};	// 노드를 방문했는 지 여부 기록

		// 시작 노드를 큐에 넣으면서 시작
		q.push(source);
		visited[source] = true;



		while(!q.empty()){
			/*
				큐에서 노드를 꺼낸 다음, 해당 노드에서 작업해야 하는
				어떤 일을 먼저 진행한다
				노드에서 작업
			*/
			int f = q.front();
			cout<< f <<endl;

			// 작업 후 제거
			q.pop();

			// Push the nbrs of current node 
			// inside q if they are not already visited
			// 현재 방문한 노드의 이웃을 큐에 넣기
			for(auto nbr : l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
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
	g.bfs(1);
	return 0;
}








