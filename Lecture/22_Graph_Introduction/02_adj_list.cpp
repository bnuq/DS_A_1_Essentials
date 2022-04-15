#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;


class Node{
public:
	string name;		// 노드에 저장되는 이름
	list<string> nbrs;	// 노드에 연결된, 다른 노드들의 이름

	Node(string name){
		this->name = name;
	}
};

class Graph{

	// 노드 이름 => 노드 위치 를 저장하는 해시맵
	unordered_map<string,Node*> m;

public:
	// 도시의 이름들
	Graph(vector<string> cities){
		for(auto city : cities){

			// 노드를 구성하는 노드 이름과 그에 대응되는 노드를 할당, 연결
			m[city] = new Node(city);
		}
	}

	void addEdge(string x,string y,bool undir=false){
		// 노드 내 저장된 이웃 리스트에 이웃을 추가
		m[x]->nbrs.push_back(y);

		if(undir){
			m[y]->nbrs.push_back(x);
		}
	}

	void printAdjList(){
		for(auto cityPair : m){
			auto city = cityPair.first;
			Node *node = cityPair.second;
			cout<<city<<"-->";

			// 해당 이름을 가지는 노드에 연결된, 이웃 노드들이 이름을 리턴
			for(auto nbr : node->nbrs){
				cout << nbr<<",";
			}
			cout<<endl;
		}
	}
};

int main(){
	vector<string> cities = {"Delhi","London","Paris","New York"};
	Graph g(cities);

	g.addEdge("Delhi","London");
	g.addEdge("New York","London");
	g.addEdge("Delhi","Paris");
	g.addEdge("Paris","New York");

	g.printAdjList();
	

	return 0;
}



