#include<iostream>
#include<list> // Double Linked List
using namespace std;


// Adjancency list 방식으로 그래프 표현
class Graph{

	int V; // 그래프를 구성하는 정점의 개수
	list<int> *l;

public:
	Graph(int v){
		V = v;

		// 리스트의 - 배열을 할당 => Adjancency list
		// l 로 각기 다른 리스트에 접근할 수 있다
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=true){
		// i -> j edge 기록
		l[i].push_back(j);

		// 방향이 없다면
		if(undir){
			// j -> i edge 도 기록
			l[j].push_back(i);
		}
	}
	

	void printAdjList(){
		//Iterate over all the rows
		// 그래프의 한 정점에 대해서
		for(int i=0;i<V;i++){
			cout<<i<<"-->";
			//every element of ith linked list
			// 연결된 다른 정점을 모두 출력한다
			for(auto node:l[i]){
				cout << node <<",";
			}
			cout <<endl;
		}
	}
};



int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.printAdjList();
	return 0;
}








