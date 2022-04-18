//File : Hashtable.h
#include<iostream>
#include<string>
using namespace std;


template<typename T> //������ Ÿ�� ���� ������ �� �ִ�
class Node {
public:
	//�ؽ��Լ��� ��� ���� key
	string key;

	//��忡 �����ϴ� value
	T value;

	//���� key �� ������ ������ �����ϴ� ������
	Node * next;

	Node(string key, T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}

	~Node(){
		if(next!=NULL){
			//�ش� ��忡 �����, �ٸ� ����� �޸𸮸� �����Ѵ�
			delete next;
		}
	}

};

template<typename T>
class Hashtable {
	//��� ���� �þ�鼭, �������� �þ�� �ϴ� �迭
	//��� �������� �迭
	Node<T>** table;

	int cs; //total entries that have been inserted
	int ts; //size of table

	
	//key �� �̿� => �ؽ� �Լ� ���� ���� �޼���
	int hashFn(string key){

		int idx = 0;
		int power = 1;

		for(auto ch : key) {

			//ts �� ���� ������ �̿� => ��ü ���̺� ����� ���� �ʵ��� �Ѵ�
			//�ؽ� �Լ� ���� ���� ��, �ؽ� ���̺� ����� ������ ��ģ��~
			idx = (idx + ch*power)%ts;
			power = (power*29)%ts;
		}
		return idx;
	}


	//�ؽ� ���̺��� �޸𸮸� �ٽ� �Ҵ��ϴ� �۾�
	//�� ū ���̺��� �������� �Ѵ�
	void rehash() {

		//Save the ptr to the oldTable and we will do insertions in the new table
		Node<T> **oldTable = table; //���� �ؽ� ���̺�
		int oldTs = ts;

		//increase the table size 
		cs = 0;
		ts = 2*ts + 1; //2�� �̻����� �ø���
		table = new Node<T>*[ts]; //you should make it prime

		for(int i=0; i<ts; i++){
			table[i] = NULL;
		}


		//Copy elements from old table to new table
		//������ �����ߴ� ������, ���ο� �ؽ� ���̺� �����Ѵ�
		//���ο� �ؽ� �Լ� ���� ����
		for(int i=0; i<oldTs; i++){

			Node<T> *temp = oldTable[i];

			while(temp!=NULL) { //�ؽ� ���̺� ����� ��� ���鿡 ���ؼ�
				string key = temp->key;
				T value = temp->value;

				//happen in the new table
				//���̺� �����Ϳ� ���̺� ����� �ٲ�����ϱ�, �ٲ� ȯ�濡�� ���� ����
				insert(key,value);
				temp = temp->next; //���� ���� �Ѿ
			}


			//destroy the ith linked list
			//�� �ű�� ����, ���� �ؽ� ���̺� �ε����� �����Ѵ�
			if(oldTable[i]!=NULL) {
				delete oldTable[i];
			}
		}
		delete[] oldTable;
	}


public:
	Hashtable(int default_size = 7){
		cs = 0;
		ts = default_size;

		//��� �������� �迭
		//�� ��� ������ => ���� �ؽ� �Լ� ���� ������, ��� ����Ʈ�� ����Ű�� �ȴ�
		table = new Node<T>*[ts];
		
		for(int i=0;i<ts;i++){
			table[i] = NULL; //ó������ ����Ű�� �� ����
		}

	}


	void insert(string key, T val) {
		
		//Node �� Ű �� => �ؽ� �Լ� ���� ����
		//= index => hash table �� �� �ε���
		int idx = hashFn(key);

		Node<T>* n = new Node<T>(key,val);

		//Insertion at head of the linked list
		//������ table ���� �ٷ� ����Ű�� �ִ� ��带, ���� ���� ��� �������� �̵���Ű��
		//���� ���� ��带 table ���� ����Ű�� �Ѵ�
		//O(1)
		n->next = table[idx];
		table[idx] = n;

		cs++; //�� �ִ� ��� ���� ����

		//��ü ������� ����ִ� ��� ���� ������ ����
		//�� ���̺� �ε��� ��, ��� �� ���� entry �� ������ �ִ°�?
		float load_factor = cs/float(ts);
		if(load_factor > 0.7) { //���� ���� �̻��̸�, �ؽ� ���̺� ����� �ø���
			rehash();
		}

	}

	//key ���� ������ ����� value �� �ּҸ� ����
	//��� �ּҸ� �����ϴ� �ŵ� �ƴϰ�, value �� �ּҸ� �����ϳ�
	T* search(string key){
		int idx = hashFn(key);

		Node<T> *temp = table[idx];

		while(temp!=NULL){
			if(temp->key == key){
				return &temp->value;
			}
			temp = temp->next;
		}

		return NULL;
	}


	//HomeWork - Code Exercise
	void erase(string key){
		//find the bucket index
		int idx = hashFn(key);

		//���� �����ϰ� �ִ� ���
		Node<T>* curNode = table[idx];

		//���� ��带 ����Ű��, ���� ���
		Node<T>* prevNode = NULL; //ó������ �����ϱ�, NULL

		//iterate over the linked list
		while (curNode != NULL) {
			
			if (curNode->key == key) { //key �� ������ ��带 ã��

				//���� ��带 ã��
				Node<T>* nextNode = curNode->next;
				
				//table ���� �ٷ� ����Ű�� ��尡 ã�� ����� ��
				if (prevNode == NULL) {
					table[idx] = nextNode;
				}//prevNode �� ����
				else prevNode->next = nextNode;

				//���� ����� ������ ���� ����
				curNode->next = NULL;
				delete curNode;

				return;
			}

			//���� ���� �̵�
			prevNode = curNode;
			curNode = curNode -> next;
		}

		return;
	}


	//�����Ͷ� ���۷����� ��� �򰥷���, ���۷��� ����غ�
	void eraseV2(string key) {
		int idx = hashFn(key);

		Node<T>* nodePtr = table[idx];
		Node<T>* prevnodePtr = nullptr;

		while (nodePtr != nullptr) {
			Node<T>& curNode = *nodePtr;

			if (curNode.key == key) {
				if (prevnodePtr == nullptr) {
					table[idx] = curNode.next;

					curNode.next = nullptr;

					delete nodePtr;
					return;
				}
				else {
					Node<T>& prevNode = *prevnodePtr;
					Node<T>& nextNode = *curNode.next;

					prevNode.next = &nextNode;

					curNode.next = nullptr;

					delete nodePtr;
					return;
				}
			}
			else {
				prevnodePtr = &curNode;
				nodePtr = curNode.next;
			}
		}
	}


	//key �� �̿��� ��带 ã��, value ����
	//return by reference => �ܺο��� ���� ������ ���� �ִ�
	T& operator[](string key) {
		//return the value 
		// if key is not found then create a new node and return
		// return the existing node
		
		//key ���� ������ ��带 ã�´�
		T* valueFound = search(key);

		//�׷� ��尡 ���� ��� => ���� �ϳ� �����
		if(valueFound==NULL){
			T object{};
			insert(key,object);

			//�׸��� ���� ��带 �ٽ� ã��
			valueFound = search(key);
		}

		//�ش� ���� ���۷��� => ���� ��ü�� ����
		return *valueFound;
	}


	void print(){
		//Iterate over buckets
		for(int i=0;i<ts;i++){
			
			//�ؽ� ���̺��� �� ��Ŷ�� ����
			cout<<"Bucket "<<i<<"->";

			Node<T> *temp = table[i];

			//�� ��Ŷ ���� ���鿡 ����
			while(temp!=NULL){
				cout<< temp ->key <<"->";
				temp = temp->next;
			}
			cout <<endl;
		}
	}
};