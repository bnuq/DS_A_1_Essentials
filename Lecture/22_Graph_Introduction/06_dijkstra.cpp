#include<iostream>
#include<list>
#include<set>
#include<vector>

using namespace std;

class Graph{
	int V;
	// Weighted Graph
	// �� edge ��, �� edge �� ������ �� �ʿ��� ����ġ�� �־��� �ִ�
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}
							
							// wt = ����ġ
	void addEdge(int u,int v,int wt,bool undir = true){
		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}


	// ���ͽ�Ʈ�� �˰��� ����
	int dijkstra(int src,int dest){

		// Data Structures ����
		vector<int> dist(V,INT_MAX);	// ������ ��������, ���ݱ��� ���� �ִ� �Ÿ��� ����
		set<pair<int,int>>  s;			// ���� �ڷᱸ��, ����ġ�� ª�� �̿� ������ �����Ѵ�
										// set + pair => pair.first �� ���� ���� �տ� ����ȴ�

		// Init 
		dist[src] = 0;		// ��� ��� -> ��� ���, �Ÿ� = 0
		s.insert({0,src});	// �湮�ϰ��� �ϴ� �̿� ������ ���� �ڷᱸ���� �ֱ� ����, ��� ������ �ִ´�


		// ���� �ڷᱸ���� �� ������ �ݺ� ����
		while(!s.empty()){

			// set �� ����� pair ��, ����ġ�� ���� ���� ��忡 �湮�Ѵ�
			auto it = s.begin();

			int node = it->second;			// �湮 ���
			int distTillNow = it->first;	// �湮 �������� �Ÿ� <= ������ �ִ� �Ÿ���� ����
			s.erase(it);					// Pop, �湮������ ���� �ڷᱸ������ �����


			// Iterate over the nbrs of node
			// �湮 ���� => ���� ����� �̿� ����� ���� �ִ� �Ÿ��� �����Ѵ�
			// nbrPair == node ���� �̿� ������ ���� �� �ɸ��� �Ÿ��� ����
			for(const auto& nbrPair : l[node]){

				int nbr = nbrPair.second;			// �̿� ���
				int currentEdge = nbrPair.first;	// ���� ��忡�� �̿� ������ ���� �� �ɸ��� �Ÿ�

				// ���� ��� => �̿� ���, �� ���� �Ÿ���, ������� ������ �̿� ������ ���� �ִ� �Ÿ��� ���Ѵ�
				if(distTillNow + currentEdge < dist[nbr]){
					// ���� ��带 ���ļ� �̿� ��带 ���� ���� �� ª�� ���
					// dist ���� �����Ѵ�
					int oldDist = dist[nbr];
					dist[nbr] = distTillNow + currentEdge;


					// dist �� ���ŵǴ� ���, �ش� ������ �ɸ��� �Ÿ��� �޶������Ƿ�
					// ���� �ڷᱸ�� �� ������ �ٽ� �ٲ��� �Ѵ�
					// remove if nbr already exist in the set
					// ���� �ش� ��尡 �̹� ���� �ڷᱸ���� �־��ٸ� �����
					auto f = s.find({oldDist, nbr});
					if(f!=s.end()){
						s.erase(f);
					}

					// insert the updated value with the new dist
					// ���ŵ� �ִ� �Ÿ��� ������, ���� �ڷᱸ���� �ִ´�
					s.insert({dist[nbr],nbr});
				}

			}
		}


		// Single Source Shortest Dist to all other nodes
		// dist �� �����, �� ������ �����ϴ� �ִ� �Ÿ� ���
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