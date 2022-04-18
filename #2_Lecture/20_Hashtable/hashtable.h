//File : Hashtable.h
#include<iostream>
#include<string>
using namespace std;


template<typename T> //임의의 타입 값을 저장할 수 있다
class Node {
public:
	//해시함수의 결과 값인 key
	string key;

	//노드에 저장하는 value
	T value;

	//같은 key 를 가지는 노드들을 연결하는 포인터
	Node * next;

	Node(string key, T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}

	~Node(){
		if(next!=NULL){
			//해당 노드에 연결된, 다른 노드의 메모리를 해제한다
			delete next;
		}
	}

};

template<typename T>
class Hashtable {
	//노드 수가 늘어나면서, 동적으로 늘어나야 하는 배열
	//노드 포인터의 배열
	Node<T>** table;

	int cs; //total entries that have been inserted
	int ts; //size of table

	
	//key 값 이용 => 해시 함수 값을 얻어내는 메서드
	int hashFn(string key){

		int idx = 0;
		int power = 1;

		for(auto ch : key) {

			//ts 로 나눈 나머지 이용 => 전체 테이블 사이즈를 넘지 않도록 한다
			//해시 함수 값을 얻어내는 데, 해시 테이블 사이즈가 영향을 끼친다~
			idx = (idx + ch*power)%ts;
			power = (power*29)%ts;
		}
		return idx;
	}


	//해시 테이블의 메모리를 다시 할당하는 작업
	//더 큰 테이블을 가지도록 한다
	void rehash() {

		//Save the ptr to the oldTable and we will do insertions in the new table
		Node<T> **oldTable = table; //기존 해시 테이블
		int oldTs = ts;

		//increase the table size 
		cs = 0;
		ts = 2*ts + 1; //2배 이상으로 늘린다
		table = new Node<T>*[ts]; //you should make it prime

		for(int i=0; i<ts; i++){
			table[i] = NULL;
		}


		//Copy elements from old table to new table
		//기존에 저장했던 노드들을, 새로운 해시 테이블에 저장한다
		//새로운 해시 함수 값을 얻어낸다
		for(int i=0; i<oldTs; i++){

			Node<T> *temp = oldTable[i];

			while(temp!=NULL) { //해시 테이블에 연결된 모든 노드들에 대해서
				string key = temp->key;
				T value = temp->value;

				//happen in the new table
				//테이블 포인터와 테이블 사이즈가 바뀌었으니까, 바뀐 환경에서 새로 삽입
				insert(key,value);
				temp = temp->next; //다음 노드로 넘어감
			}


			//destroy the ith linked list
			//다 옮기고 나면, 기존 해시 테이블 인덱스를 제거한다
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

		//노드 포인터의 배열
		//각 노드 포인터 => 같은 해시 함수 값을 가지는, 노드 리스트를 가리키게 된다
		table = new Node<T>*[ts];
		
		for(int i=0;i<ts;i++){
			table[i] = NULL; //처음에는 가리키는 것 없음
		}

	}


	void insert(string key, T val) {
		
		//Node 의 키 값 => 해시 함수 값을 얻어낸다
		//= index => hash table 에 들어갈 인덱스
		int idx = hashFn(key);

		Node<T>* n = new Node<T>(key,val);

		//Insertion at head of the linked list
		//기존에 table 에서 바로 가리키고 있던 노드를, 새로 생긴 노드 다음으로 이동시키고
		//새로 만든 노드를 table 에서 가리키게 한다
		//O(1)
		n->next = table[idx];
		table[idx] = n;

		cs++; //들어가 있는 노드 개수 증가

		//전체 사이즈와 들어있는 노드 개수 비율을 조사
		//한 테이블 인덱스 당, 평균 몇 개의 entry 를 가지고 있는가?
		float load_factor = cs/float(ts);
		if(load_factor > 0.7) { //일정 개수 이상이면, 해시 테이블 사이즈를 늘린다
			rehash();
		}

	}

	//key 값을 가지는 노드의 value 의 주소를 리턴
	//노드 주소를 리턴하는 거도 아니고, value 의 주소를 리턴하네
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

		//현재 조사하고 있는 노드
		Node<T>* curNode = table[idx];

		//현재 노드를 가리키는, 이전 노드
		Node<T>* prevNode = NULL; //처음에는 없으니까, NULL

		//iterate over the linked list
		while (curNode != NULL) {
			
			if (curNode->key == key) { //key 가 동일한 노드를 찾고

				//다음 노드를 찾아
				Node<T>* nextNode = curNode->next;
				
				//table 에서 바로 가리키던 노드가 찾던 노드일 때
				if (prevNode == NULL) {
					table[idx] = nextNode;
				}//prevNode 가 존재
				else prevNode->next = nextNode;

				//현재 노드의 연결을 끊고 제거
				curNode->next = NULL;
				delete curNode;

				return;
			}

			//다음 노드로 이동
			prevNode = curNode;
			curNode = curNode -> next;
		}

		return;
	}


	//포인터랑 레퍼런스가 잠깐 헷갈려서, 레퍼런스 사용해봄
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


	//key 를 이용해 노드를 찾고, value 수정
	//return by reference => 외부에서 값을 수정할 수도 있다
	T& operator[](string key) {
		//return the value 
		// if key is not found then create a new node and return
		// return the existing node
		
		//key 값을 가지는 노드를 찾는다
		T* valueFound = search(key);

		//그런 노드가 없는 경우 => 새로 하나 만든다
		if(valueFound==NULL){
			T object{};
			insert(key,object);

			//그리고 넣은 노드를 다시 찾아
			valueFound = search(key);
		}

		//해당 변수 레퍼런스 => 변수 자체를 리턴
		return *valueFound;
	}


	void print(){
		//Iterate over buckets
		for(int i=0;i<ts;i++){
			
			//해시 테이블의 각 버킷에 접근
			cout<<"Bucket "<<i<<"->";

			Node<T> *temp = table[i];

			//한 버킷 안의 노드들에 접근
			while(temp!=NULL){
				cout<< temp ->key <<"->";
				temp = temp->next;
			}
			cout <<endl;
		}
	}
};