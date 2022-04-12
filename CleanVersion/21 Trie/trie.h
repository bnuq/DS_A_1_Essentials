
#include<unordered_map>
#include<string>
using namespace std;

class Trie;


class Node { // 트리 구조를 만드는 노드

	char data;

	// 다음 노드를 가리킬 수 있는데, 개수가 제한되어 있지 않다
	// 다음 가리키는 노드의 값은 a-z 중 하나, 중복 없고
	// Hashing 을 이용해서 다음 노드 위치를 저장한다
	unordered_map<char,Node*> m;
	
	// 문자열의 끝임을 알림
	bool isTerminal;

public:

	Node(char d){
		data = d;
		isTerminal = false;
	}

	friend class Trie;
};


class Trie{
	// root node 는 /0, 그냥 비어 있음
	Node*root;
	
public:
	Trie(){
		root = new Node('\0');
	}


	
	//Insertion
	void insert(string word){ // word 를 trie 에 넣고 싶다
		// root node 부터 시작
		Node* temp = root;

		for(char ch : word){ // 각 알파벳을 처리
			
			/*
				unordered_map::count(key)
				해당 노드의 HashMap 에서 ch 를 key 로 가지는 entry 가 존재하는 지 확인
				entry 가 하나라도 존재하면, 1 return 없으면 0 return
  			 */
			if(temp->m.count(ch)==0){
				// ch 를 가지는 노드를 만들고
				Node*n = new Node(ch);

				// HashMap 에 연결 => 그 노드를 가리키게 한다
				temp->m[ch] = n;
			}
			// 연결된 다음 노드로 이동
			temp = temp->m[ch];
		}

		// word 의 마지막 문자를 가지는 노드까지 이동했다
		// 해당 문자가 마지막이므로, 문자열의 마지막임을 알린다
		temp->isTerminal = true;
	}



	//Searching
	bool search(string word){
		// root node 에서 시작
		Node*temp = root;

		// 전체 문자열에 대해서
		for(char ch:word){
			// 다음 문자가 trie 에 존재하는 지 확인
			if(temp->m.count(ch)==0){
				return false;
			}
			temp = temp->m[ch];
		}
		// 마지막 문자에 도착, 그게 마지막 terminal 로 표시됐는 지 확인
		return temp->isTerminal;
	}
};






