/*
	택시의 이름과 2차원 좌표가 주어진다 (N개)
	나는 2차원 원점에 서있다
	내 위치에서 가장 가까운 택시 k 개를 찾아라
*/


//나로부터 떨어진 거리를 자동으로 정렬할 필요가 있다
//Heap 에 담으면, 여러 값들 중에서, 자동으로 가장 크거나 가장 작은 값을 구할 수 있다

//정렬이 목적이 아니고, 그냥 최대/최소 값을 구할 때 => Heap 사용
//전체 구간을 정렬할 필요가 없을 때


/*
	Heap 을 이용하는 건 똑같은데
	전체 요소에 대해서, 다 Heap 에 넣을 필요가 없다

	k 개만 필요하니까, k 개만 담는 Heap 을 만들고 이용한다
	Max Heap 이용 => 해당 Heap 에서 가장 큰 값이 꼭대기에 위치하게 한다

	top() 보다 큰 값 = 작은 k 개에 들어가지 않는다 => 애초에 Heap 에 넣지도 않아
	top() 보다 작은 값 => top() 을 제거하고 추가 => heapify
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
			 //const 안 쓰니까, const object 에서 호출이 안된다
	int dist() const { return x * x + y * y; }
};


struct CarCompare {					  //만드려는 것 = Max Heap
	bool operator()(Car& a, Car& b) { //왼쪽 => heap 에서 내려가 => 작은 값이 내려가게 하자
		
		return a.dist() < b.dist();
	}
};


void printNearestCars(vector<Car>& cars, int k) {

	//k 개만 저장하는 max heap 을 만든다 => 값이 작은 k 개만 저장할 목적
													//vector iterator 로 heap에 들어갈 값일 지정할 수 있다
													//vector 의 처음 k 개를 바로 heap 에 넣는다
	priority_queue<Car, vector<Car>, CarCompare> maxHeap(cars.begin(), cars.begin() + k); //마지막은 포함 안함

	//Remaining cars 처리
	for (int i = k; i < cars.size(); i++) {
		auto car = cars[i];

		if (car.dist() < maxHeap.top().dist()) { //더 작은 값이 존재 => top() 날리고, 새로 넣는다
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

		=> 근데, 이대로 출력하면 max heap => k 개의 작은 값들이, 내림차순으로 출력된다
	*/

	//Stack 을 이용해서 뒤집어 주자
	//아니면 vector 에 담아서 => reverse 이용
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