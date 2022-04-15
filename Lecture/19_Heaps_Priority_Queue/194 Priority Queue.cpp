#include <iostream>

//Priority Queue 사용을 위해서는 queue 를 사용할 수 있어야 한다
#include <queue>
using namespace std;


//priority_queue 에서 사용할 Comparator 를 직접 만들 수도 있다
//Function Object
template <typename T>
struct myCompare {
	//function call operator
	bool operator()(T a, T b) {

		//왼쪽에 더 큰게 와야 한다
		return a > b;
	}
};



int main() {
	int arr[]{ 10, 15, 20, 13,6, 90 };
	int arrSize{ sizeof(arr) / sizeof(int) };

	//priority queue 정의
	//Heap 과 같은 역할을 한다
	priority_queue<int> maxHeap{}; //Default Priority Queue = Max Heap

	//다른 종류의 Heap 을 만들기 위해서는, Comparator 를 지정해주어야 한다
	//type, Container, Comparator
	priority_queue<int, vector<int>, greater<int>> minHeap{};

	/*
		priority_queue 에서 Comparator 직접 지정
		function object => 객체가 아닌 타입만 넘긴다 => 내부적으로 호출할 수 있게?
		
		비교할 때 왼쪽에 큰 게 오게 하니까 => 작은게 꼭대기로 온다
		왼쪽 => 밑, 오른쪽 => 꼭대기 인듯
		
		중간 template argument 생략하면, 컴파일러가 인식 못한다
	*/
	priority_queue<int, vector<int>, myCompare<int>> myHeap{};


	for (int x : arr) {
		/*
			priority_queue::push()

			Heap 에 Insert 하는 역할
		*/
		//minHeap.push(x);
		myHeap.push(x);
	}

	/*
		priority_queue::empty()
	*/
	while (!myHeap.empty()) {
		/*
			priority_queue::top()
		*/
		//cout << minHeap.top() << endl;
		cout << myHeap.top() << endl;
		
		/*
			priority_queue::pop()
		*/
		//minHeap.pop();
		myHeap.pop();
	}



}