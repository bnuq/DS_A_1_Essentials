#include <iostream>

//Priority Queue ����� ���ؼ��� queue �� ����� �� �־�� �Ѵ�
#include <queue>
using namespace std;


//priority_queue ���� ����� Comparator �� ���� ���� ���� �ִ�
//Function Object
template <typename T>
struct myCompare {
	//function call operator
	bool operator()(T a, T b) {

		//���ʿ� �� ū�� �;� �Ѵ�
		return a > b;
	}
};



int main() {
	int arr[]{ 10, 15, 20, 13,6, 90 };
	int arrSize{ sizeof(arr) / sizeof(int) };

	//priority queue ����
	//Heap �� ���� ������ �Ѵ�
	priority_queue<int> maxHeap{}; //Default Priority Queue = Max Heap

	//�ٸ� ������ Heap �� ����� ���ؼ���, Comparator �� �������־�� �Ѵ�
	//type, Container, Comparator
	priority_queue<int, vector<int>, greater<int>> minHeap{};

	/*
		priority_queue ���� Comparator ���� ����
		function object => ��ü�� �ƴ� Ÿ�Ը� �ѱ�� => ���������� ȣ���� �� �ְ�?
		
		���� �� ���ʿ� ū �� ���� �ϴϱ� => ������ ������ �´�
		���� => ��, ������ => ����� �ε�
		
		�߰� template argument �����ϸ�, �����Ϸ��� �ν� ���Ѵ�
	*/
	priority_queue<int, vector<int>, myCompare<int>> myHeap{};


	for (int x : arr) {
		/*
			priority_queue::push()

			Heap �� Insert �ϴ� ����
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