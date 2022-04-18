#include <iostream>
using namespace std;

/*
* Bubble Sort
* 처음부터 끝까지 조사하는 것을 반복, 매 조사마다 거품이 올라오는 것처럼 가장 큰 값을 뒤로 보낸다
* 이번과 다음만 비교, 인접한 것 끼리만 swap 을 한다
*/
void bubble_sort(int a[], int n) {
	// 총 개수 - 1 번 반복한다
	for (int times = 1; times <= n - 1; times++) {
		//repeated swapping
		// 처음부터 끝 원소까지 조사한다, 매 반복마다 끝에서부터 차례대로 정렬된다
		// 중간에 swap 하는 경우가 없어도 상관없다 => 결국 가장 큰 값은 보내니까
		for (int j = 0; j <= n - times - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]); // swap 함수 애용
			}
		}

	}
}

/*
* Insertion Sort
* 손에서 카드를 정렬하는 방법과 동일하게 진행
* 왼쪽에 있는 카드부터 정렬 => 점점 오른쪽의 카드를 추가, 정렬된 패를 늘린다
* 오른쪽에 있는 카드를 추가해 적절한 위치에 꽂아 넣는다
*/
void insertion_sort(int a[], int n) {
	for (int i = 1; i <= n - 1; i++) {
		int current = a[i]; // 정렬하고자 하는 카드
		int prev = i - 1; // 꽂으려는 위치 앞 위치를, 인덱스를 통해 나타낸다
		// loop to find the right index where the element current should be inserted
		// 앞 위치 정보를 보면서, 내가 넣고자 하는 위치를 파악한다
		while (prev >= 0 and a[prev] > current) {
			a[prev + 1] = a[prev]; // 값 복사 => 카드의 이동을 의미
			prev = prev - 1;
		}
		a[prev + 1] = current;
	}
}

/*
* Selection Sort
* 정렬되지 않은 구간에서 가장 작은 값을 찾아서 가져와 ~
* 왼쪽에서부터 정렬한다
*/
void selection_sort(int a[], int n) {
	// pos = 이번에 값을 넣고자 하는 위치
	for (int pos = 0; pos < n - 1; pos++) {
		int current = a[pos];
		int min_position = pos; // 일단 현재 값을 최소 값이라 가정하고
		//find out the element 
		for (int j = pos+1; j < n; j++) {
			if (a[j] < a[min_position]) {
				min_position = j; // 가장 작은 값이 있는 위치만 가져온다
			}
		}
		// swap outside the loop
		// swap 을 통해서, 가장 작은 값을 앞으로 가져온다
		swap(a[min_position], a[pos]);
	}
}

/*
* <algorithm> :: sort() => 간단하게 정렬이 가능하다
* <algorithm> :: reverse() => container element 순서를 거꾸로 나열한다
* 비교하는 방식 지정 가능 => comparator 지정
*/
#include <algorithm>
// function pointer
bool compare(int a, int b) {
	//cout<<"Comparing "<<a <<" and "<<b <<endl;
	return a < b;
}
// function object
template<typename T>
struct compObj
{
	bool operator ()(const T& a, const T& b) {
		return a < b;
	}
};
void inbuiltFunc() {
	int arr[] = { 10,9,8,6,5,4,3,2,11,16,8 };
	int n = sizeof(arr) / sizeof(int);

	sort(arr, arr + n); // 기본적으로는 non-decreasing order 로 정렬한다

	// function pointer 로 전달 => sort function 내에서 비교할 떄 해당 함수를 호출한다
	sort(arr, arr + n, compare); // sort : 비교함수를 이용해서 정렬하는 함수
	
	// function object
	compObj<int> cObj{};
	sort(arr, arr + n, cObj);

	// Lambda expression
	sort(arr, arr + n, [](const auto& e1, const auto& e2) {
		return e1 > e2;
		});

	//Print the ouput
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl << endl;

	reverse(arr, arr + n);	  // reverse : 배열을 뒤집어 주는 함수
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl << endl;


	// 내부적으로 이미 정의된 competitor => bool return 하기 떄문에 predicate 로 부른다
	// function object 인듯?
	sort(arr, arr + n, greater<int>()); // 큰 값이 왼쪽에 온다
	sort(arr, arr + n, less<int>()); // 작은 값이 왼쪽에 온다
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl << endl;
}

/*
* Counting Sort ~ O(range + n)
* 데이터 값의 범위가 한정되어 있을 때 사용, 값의 범위만큼 길이를 가지는 배열 frequency vector 이용
* 어떤 값이 존재하면, 그 값이 인덱스인 ~ 배열의 값을 증가시킨다
* 이후 frequency vector 의 값이 얼마인지를 파악한다
*/
#include <vector>
void counting_sort(int a[], int n) {
	//Largest Element
	int largest = -1;
	for (int i = 0; i < n; i++) {
		largest = max(largest, a[i]); // 최대값 => 값의 범위를 알아낸다
	}
	//create a count array/vector
	vector<int> freq(largest + 1, 0); // fill constructor
	//Update the freq array 
	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
	}
	//Put back the elements from freq into original array
	int j = 0; // original vector 에 넣는 인덱스
	for (int i = 0; i <= largest; i++) { // freq vector 를 돌아
		while (freq[i] > 0) {
			a[j] = i;
			freq[i]--;
			j++;
		}
	}
	return;
}


int main() {
}