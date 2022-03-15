/*
* std::vector
* 
* Data Member
	* array
	* size => 실제 사용하는 공간 => 접근 가능
	* capacity => 실제 메모리를 할당한 공간 => 접근 불가능
* 
* Member Function
	* push_back(d) => 뒤에 삽입, capacity 가 부족하면 기존의 2배를 재할당해서 새로 벡터를 만든다
	* pop_back() => 뒤의 것 삭제
	
	* front()
	* back()
	 
	* empty() => vector 가 비었는 지, 아닌지
	* at(i)
	* size()
	* capacity()

	* emplace_back(d) => 뒤에 값 추가, 복사해서 넣지 않고 벡터에 공간을 만들면서 바로 초기화한다
	* emplace(itr, d) => itr 앞에 값을 추가해준다, list 처럼 사용이 가능하다
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<string, int> f1, pair<string, int> f2) {
	
	// comparator 가 리턴할 때, 왼쪽에 있는 것이 실제로 왼쪽에 정렬된다고 생각하면 된다
	// 즉, second 값이 큰 것 => 작은 것, 순서로 정렬될 것이다
	return f1.second > f2.second;
}

void vectorDemo(int row, int col) {
	// Fill Constructor, 이용해서 2차원 벡터 만들기
	vector<vector<int>> vec1(row, vector<int>(col, 10));
	//vector<vector<int>> vec2{ row, vector<int>{col, 100} };

	vector<pair<string, int> > fruits = {
		{"apple",10},
		{"mango",100},
		{"guava",20},
		{"papaya",40},
		{"orange",60},
		{"banana",120},
	};

	// vector => iterator 존재 => sort 로 정렬할 수 있다
	// function pointer, function object, lambda expression 모두 사용 가능
	sort(fruits.begin(), fruits.end(), compare);

	// emplace 사용 => 객체를 넣지 않고 그 객체를 만드는 데 필요한 argument 만 넣어주면 된다
	fruits.emplace_back("string", 99);
	fruits.emplace(fruits.end(), "keroro", 90);
	// emplace 는 중간에 삽입도 가능하다 => array 인데 중간 삽입이 가능하다!
	fruits.emplace(fruits.begin() + 3, "앞에 3개가 있다", 999);

	for (auto x : fruits)
		cout << x.first << " , " << x.second << endl;
}

void vectorSearch() {

	vector<int> arr = { 10,11,2,3,4,6,7,8 };
	int key{ 2 };
	
	/*
	algorithm :: find function => 주어진 key 를 찾는다
	key 가 존재하는 iterator 를 리턴
	못 찾으면 end() 리턴
	*/
	vector<int>::iterator it = find(arr.begin(), arr.end(), key);
	if (it != arr.end()) {
		cout << "Present at index " << it - arr.begin() << " , " << *it << endl;
	}
	else {
		cout << "Element not found" << endl;
	}


	/*
	algorithm :: search function => subsequence 가 존재하는 지 찾을 때 쓰인다
	동일한 subsequence 가 존재한다면, 시작 위치 iterator return
	*/
	vector<int> bigVec{ 1,2,3,4,5,6,7 };
	vector<int> smallVec{ 4,5,6 };
	vector<int> otherVec{ 6,7,8 };

	vector<int>::iterator itr;
	// 찾으려는 sequence 범위와 대상 sequence 범위를 지정
	itr = search(bigVec.begin(), bigVec.end(), smallVec.begin(), smallVec.end());
	if (itr != bigVec.end())
		cout << itr - bigVec.begin() << " , " << *itr << endl;

	itr = search(bigVec.begin(), bigVec.end(), otherVec.begin(), otherVec.end());
	if (itr != bigVec.end())
		cout << itr - bigVec.begin() << " , " << *itr << endl;
	else
		cout << "No element" << endl;


	// Predicate( comparator ) 추가 버전 => lambda expression = function object 사용
	itr = search(bigVec.begin(), bigVec.end(), otherVec.begin(), otherVec.end(), [](const auto& e1, const auto& e2) {
		// 그냥 무조건 맞다고 해
		return true;
		});
	if (itr != bigVec.end())
		cout << itr - bigVec.begin() << " , " << *itr << endl;
	else
		cout << "No element" << endl;


	
	vector<int> aVec{ 2,3,1,5,4,8,1,9,4 };

	/*
	이미 정렬된 vector 라면 => 이진탐색으로 더 빠른 검색을 할 수 있다
	algorithm :: binary_search function 이용
	*/
	sort(aVec.begin(), aVec.end());
	cout << binary_search(aVec.begin(), aVec.end(), 3) << endl;


	/*
	lower_bound
		returns an iterator to the first element not less than the given value
		given value 와 같거나 큰 값 중, 첫번째로 만난 것의 위치를 리턴
	upper_bound
		returns an iterator to the first element greater than a certain value
		given value 보다 무조건 큰 값 중, 가장 먼저 만난 것의 위치 리턴
	*/
	vector<int> bVec{ 2,3,1,5,4,8,1,9,4 };
	itr = lower_bound(bVec.begin(), bVec.end(), 8);
	cout << itr - bVec.begin() << " , " << *itr << endl;

	itr = upper_bound(bVec.begin(), bVec.end(), 8);
	cout << itr - bVec.begin() << " , " << *itr << endl;
}



int main() {
	vectorSearch();
}