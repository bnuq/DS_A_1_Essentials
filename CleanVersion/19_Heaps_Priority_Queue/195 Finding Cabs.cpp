/*
	�ý��� �̸��� 2���� ��ǥ�� �־����� (N��)
	���� 2���� ������ ���ִ�
	�� ��ġ���� ���� ����� �ý� k ���� ã�ƶ�
*/


//���κ��� ������ �Ÿ��� �ڵ����� ������ �ʿ䰡 �ִ�
//Heap �� ������, ���� ���� �߿���, �ڵ����� ���� ũ�ų� ���� ���� ���� ���� �� �ִ�

//������ ������ �ƴϰ�, �׳� �ִ�/�ּ� ���� ���� �� => Heap ���
//��ü ������ ������ �ʿ䰡 ���� ��


/*
	Heap �� �̿��ϴ� �� �Ȱ�����
	��ü ��ҿ� ���ؼ�, �� Heap �� ���� �ʿ䰡 ����

	k ���� �ʿ��ϴϱ�, k ���� ��� Heap �� ����� �̿��Ѵ�
	Max Heap �̿� => �ش� Heap ���� ���� ū ���� ����⿡ ��ġ�ϰ� �Ѵ�

	top() ���� ū �� = ���� k ���� ���� �ʴ´� => ���ʿ� Heap �� ������ �ʾ�
	top() ���� ���� �� => top() �� �����ϰ� �߰� => heapify
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

struct Car {
	string id{};
	int x{}, y{};

	Car(string aid, int ax, int ay) 
		: id{ aid }, x{ ax }, y{ ay } {

	}
			 //const �� ���ϱ�, const object ���� ȣ���� �ȵȴ�
	int dist() const { return x * x + y * y; }
};


struct CarCompare {					  //������� �� = Max Heap
	bool operator()(Car& a, Car& b) { //���� => heap ���� ������ => ���� ���� �������� ����
		
		return a.dist() < b.dist();
	}
};


void printNearestCars(vector<Car>& cars, int k) {

	//k ���� �����ϴ� max heap �� ����� => ���� ���� k ���� ������ ����
													//vector iterator �� heap�� �� ���� ������ �� �ִ�
													//vector �� ó�� k ���� �ٷ� heap �� �ִ´�
	priority_queue<Car, vector<Car>, CarCompare> maxHeap(cars.begin(), cars.begin() + k); //�������� ���� ����

	//Remaining cars ó��
	for (int i = k; i < cars.size(); i++) {
		auto car = cars[i];

		if (car.dist() < maxHeap.top().dist()) { //�� ���� ���� ���� => top() ������, ���� �ִ´�
			maxHeap.pop();
			maxHeap.push(car);
		}
	}

	/*
		Print all the cars insidethe heap
	
		while (!maxHeap.empty()) {
			cout << maxHeap.top().id << endl;
			maxHeap.pop();
		}

		=> �ٵ�, �̴�� ����ϸ� max heap => k ���� ���� ������, ������������ ��µȴ�
	*/

	//Stack �� �̿��ؼ� ������ ����
	//�ƴϸ� vector �� ��Ƽ� => reverse �̿�
	stack<Car> s{};
	while (!maxHeap.empty()) {
		s.push(maxHeap.top());
		maxHeap.pop();
	}

	while (!s.empty()) {
		cout << s.top().id << endl;
		s.pop();
	}
}


int main() {
		
	vector<Car> cars{};
	cars.emplace_back("c1", 1, 1);
	cars.emplace_back("c2", 2, 1);
	cars.emplace_back("c3", 3, 2);
	cars.emplace_back("c4", 0, 1);
	cars.emplace_back("c5", 2, 3);
	cars.emplace_back("c6", 10, 3);


	int K = 4;

	printNearestCars(cars, K);

	return 0;
}