#include<iostream>
#include<list> // Double Linked List
using namespace std;


// Adjancency list ������� �׷��� ǥ��
class Graph{

	int V; // �׷����� �����ϴ� ������ ����
	list<int> *l;

public:
	Graph(int v){
		V = v;

		// ����Ʈ�� - �迭�� �Ҵ� => Adjancency list
		// l �� ���� �ٸ� ����Ʈ�� ������ �� �ִ�
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=true){
		// i -> j edge ���
		l[i].push_back(j);

		// ������ ���ٸ�
		if(undir){
			// j -> i edge �� ���
			l[j].push_back(i);
		}
	}
	

	void printAdjList(){
		//Iterate over all the rows
		// �׷����� �� ������ ���ؼ�
		for(int i=0;i<V;i++){
			cout<<i<<"-->";
			//every element of ith linked list
			// ����� �ٸ� ������ ��� ����Ѵ�
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








