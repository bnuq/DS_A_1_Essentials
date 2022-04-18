
#include<unordered_map>
#include<string>
using namespace std;

class Trie;


class Node { // Ʈ�� ������ ����� ���

	char data;

	// ���� ��带 ����ų �� �ִµ�, ������ ���ѵǾ� ���� �ʴ�
	// ���� ����Ű�� ����� ���� a-z �� �ϳ�, �ߺ� ����
	// Hashing �� �̿��ؼ� ���� ��� ��ġ�� �����Ѵ�
	unordered_map<char,Node*> m;
	
	// ���ڿ��� ������ �˸�
	bool isTerminal;

public:

	Node(char d){
		data = d;
		isTerminal = false;
	}

	friend class Trie;
};


class Trie{
	// root node �� /0, �׳� ��� ����
	Node*root;
	
public:
	Trie(){
		root = new Node('\0');
	}


	
	//Insertion
	void insert(string word){ // word �� trie �� �ְ� �ʹ�
		// root node ���� ����
		Node* temp = root;

		for(char ch : word){ // �� ���ĺ��� ó��
			
			/*
				unordered_map::count(key)
				�ش� ����� HashMap ���� ch �� key �� ������ entry �� �����ϴ� �� Ȯ��
				entry �� �ϳ��� �����ϸ�, 1 return ������ 0 return
  			 */
			if(temp->m.count(ch)==0){
				// ch �� ������ ��带 �����
				Node*n = new Node(ch);

				// HashMap �� ���� => �� ��带 ����Ű�� �Ѵ�
				temp->m[ch] = n;
			}
			// ����� ���� ���� �̵�
			temp = temp->m[ch];
		}

		// word �� ������ ���ڸ� ������ ������ �̵��ߴ�
		// �ش� ���ڰ� �������̹Ƿ�, ���ڿ��� ���������� �˸���
		temp->isTerminal = true;
	}



	//Searching
	bool search(string word){
		// root node ���� ����
		Node*temp = root;

		// ��ü ���ڿ��� ���ؼ�
		for(char ch:word){
			// ���� ���ڰ� trie �� �����ϴ� �� Ȯ��
			if(temp->m.count(ch)==0){
				return false;
			}
			temp = temp->m[ch];
		}
		// ������ ���ڿ� ����, �װ� ������ terminal �� ǥ�õƴ� �� Ȯ��
		return temp->isTerminal;
	}
};






