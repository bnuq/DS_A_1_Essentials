#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;


class Node{
public:
	string name;		// ��忡 ����Ǵ� �̸�
	list<string> nbrs;	// ��忡 �����, �ٸ� ������ �̸�

	Node(string name){
		this->name = name;
	}
};

class Graph{

	// ��� �̸� => ��� ��ġ �� �����ϴ� �ؽø�
	unordered_map<string,Node*> m;

public:
	// ������ �̸���
	Graph(vector<string> cities){
		for(auto city : cities){

			// ��带 �����ϴ� ��� �̸��� �׿� �����Ǵ� ��带 �Ҵ�, ����
			m[city] = new Node(city);
		}
	}

	void addEdge(string x,string y,bool undir=false){
		// ��� �� ����� �̿� ����Ʈ�� �̿��� �߰�
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

			// �ش� �̸��� ������ ��忡 �����, �̿� ������ �̸��� ����
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



