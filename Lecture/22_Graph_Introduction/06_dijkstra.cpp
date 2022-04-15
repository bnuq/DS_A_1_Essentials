#include<iostream>
#include<list>
#include<set>
#include<vector>

using namespace std;

class Graph{
	int V;
	// Weighted Graph
	// 각 edge 에, 그 edge 를 지나는 데 필요한 가중치가 주어져 있다
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}
							
							// wt = 가중치
	void addEdge(int u,int v,int wt,bool undir = true){
		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}


	// 다익스트라 알고리즘 실행
	int dijkstra(int src,int dest){

		// Data Structures 정의
		vector<int> dist(V,INT_MAX);	// 임의의 노드까지의, 지금까지 계산된 최단 거리를 저장
		set<pair<int,int>>  s;			// 순서 자료구조, 가중치가 짧은 이웃 노드부터 조사한다
										// set + pair => pair.first 가 작은 것이 앞에 저장된다

		// Init 
		dist[src] = 0;		// 출발 노드 -> 출발 노드, 거리 = 0
		s.insert({0,src});	// 방문하고자 하는 이웃 노드들을 순서 자료구조에 넣기 위해, 출발 노드부터 넣는다


		// 순서 자료구조가 빌 때까지 반복 시행
		while(!s.empty()){

			// set 에 저장된 pair 중, 가중치가 가장 작은 노드에 방문한다
			auto it = s.begin();

			int node = it->second;			// 방문 노드
			int distTillNow = it->first;	// 방문 노드까지의 거리 <= 무조건 최단 거리라고 생각
			s.erase(it);					// Pop, 방문했으니 순서 자료구조에서 지운다


			// Iterate over the nbrs of node
			// 방문 목적 => 현대 노드의 이웃 노드들로 가는 최단 거리를 갱신한다
			// nbrPair == node 에서 이웃 노드까지 가는 데 걸리는 거리를 저장
			for(const auto& nbrPair : l[node]){

				int nbr = nbrPair.second;			// 이웃 노드
				int currentEdge = nbrPair.first;	// 현재 노드에서 이웃 노드까지 가는 데 걸리는 거리

				// 현재 노드 => 이웃 노드, 로 가는 거리와, 현재까지 조사한 이웃 노드까지 가는 최단 거리를 비교한다
				if(distTillNow + currentEdge < dist[nbr]){
					// 현재 노드를 거쳐서 이웃 노드를 가는 것이 더 짧은 경우
					// dist 값을 갱신한다
					int oldDist = dist[nbr];
					dist[nbr] = distTillNow + currentEdge;


					// dist 가 갱신되는 경우, 해당 노드까지 걸리는 거리가 달라졌으므로
					// 순서 자료구조 내 순서도 다시 바뀌어야 한다
					// remove if nbr already exist in the set
					// 만약 해당 노드가 이미 순서 자료구조에 있었다면 지우고
					auto f = s.find({oldDist, nbr});
					if(f!=s.end()){
						s.erase(f);
					}

					// insert the updated value with the new dist
					// 갱신된 최단 거리를 가지고, 순서 자료구조에 넣는다
					s.insert({dist[nbr],nbr});
				}

			}
		}


		// Single Source Shortest Dist to all other nodes
		// dist 에 저장된, 각 정점에 도달하는 최단 거리 출력
		for(int i=0;i<V;i++){
			cout<<"Node i "<<i <<" Dist "<<dist[i] <<endl;
		}
		return dist[dest];
	}

};

int main(){

	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,4)<<endl;
}