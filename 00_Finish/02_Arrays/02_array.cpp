#include<iostream>
using namespace std;

/*
* non-type template argument 쓰면 size 알 수 있다
* array reference 에 size 정보가 들어있다
*/
template<typename T, int size>
void printArrayRef(T(&arrRef)[size])
{
	arrRef[0] = 100;
	for (int i = 0; i < size; i++) {
		cout << arrRef[i] << endl;
	}
}

void cStyleArray() {
	// C-Style array
	// 초기화 가능, 이후 빈 공간은 0으로 초기화
	int marks[100]{ -1 };
	for (int i = 0; i < 100; i++) {
		cout << marks[i] << " ,";
	}

	/*
	* C-Style Array 방식 = pointer 방식 => 주소를 이용
	* 그래서 array size 를 알 수 없다 => 개인이 직접 넘겨주어야 한다
	* 아니면 직접 구하기
	*/
	int n = sizeof(marks) / sizeof(int); // 원소 개수, 100 계산
	sizeof(marks); // = 배열 전체 크기

	printArrayRef(marks);
}

/*
* linear search
* 그냥 처음부터 끝까지 순서대로 찾는 것
* O(n)
*/
int linear_search(int arr[], int n, int key) {
	// 그냥 전체 배열을 훑으면서 찾아
	for (int i = 0; i < n; i++) {
		//Check if current element matches with the key
		if (arr[i] == key) {
			return i;
		}
	}
	//out of the loop 
	return -1;
}

/*
* binary search
* 이미 정렬된 배열 => 범위를 반씩 나눠가면서 찾기
*/
int binary_search(int arr[], int n, int key) {
	// 검색 범위를 나타내는 인덱스 => 인덱스를 사용하는 방식을 많이 쓰더라
	// 깃발을 꼽아두는 느낌?
	int s = 0;
	int e = n - 1;
	
	// 검색 범위를 좁힌다 => 서로 어긋날 때 까지 반복하는 식
	while (s <= e) {
		int mid = (s + e) / 2; // 중간지점

		if (arr[mid] == key) {
			return mid;
		}

		// 검색 범위를 수정한다
		else if (arr[mid] > key) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return -1;
}

/*
* Problem : 특정 배열 원소들의 순서를 뒤집고 싶다
* Brute Force 하게 접근하면..? => 배열의 뒤에서부터 값을 꺼내, 뒤집어진 배열을 만든다
* or 내가 생각했던 in-place algorithm => temp 공간을 2개 만들고, 하나씩 임시저장하고 옮기고 다시 임시저장하고... 반복
* 근데 선생님은 더 간단하게 해결 => swap
	* 특정 메모리 공간을 만들거나, 뭐가 일렬로 주어진대로 해결하지 않고
	* 앞 뒤를 뒤집어주면, 결과적으로 뒤집어진 결과가 나온다 ~
	* 나도 무조건 한쪽방향으로 복사하고 이동하는 거 말고, swap 하는 경우를 생각해보도록 하자
*/
void reverseArray(int arr[], int n) {

	int s = 0;
	int e = n - 1;

	// 범위를 줄여가면서, 앞 뒤를 서로 바꿔준다
	while (s < e) {
		swap(arr[s], arr[e]);
		s += 1;
		e -= 1;
	}

}

// Problem : Print all subarrays of a given array
// Brute Force Approach O(N^3)
int largestSubarraySum1(int arr[], int n) {
	int largest_sum = 0;
	// i = 시작 범위, j = 끝 범위, k = subarray element
	// 반복할 때, 각 변수가 무엇을 뜻하는 지 확실히 파악하자
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int subarraySum = 0;
			for (int k = i; k <= j; k++) {
				subarraySum += arr[k];
			}
			//put a check is subarraySum > largest_sum
			// algorithm header 에서 제공하는 max => 더 큰 값을 리턴 => 나도 이용하자
			largest_sum = max(largest_sum, subarraySum);
		}
	}
	return largest_sum;
}

/*
* Prefix Sum Approach O(N^2)
* Prefix Sum 이라는 개념 => 구간 합, 앞에서부터 현재까지 합
* 미리 계산해 놓으면 특정 구간의 합을 쉽게 구할 수 있다
*/
int largestSubarraySum2(int arr[], int n) {

	int prefix[100] = { 0 };
	prefix[0] = arr[0];

	// prefix sum 을 구하는 과정 => 앞에서부터 누적합을 구한다	
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	int largest_sum = 0;

	for (int i = 0; i < n; i++) { // 가능한 모든 sub array 에 대하여
		for (int j = i; j < n; j++) {
			// 특정 구간 내 합을 구하는 과정을, O(n) 이 아닌 O(1) 로 해결
			// 3중 연산자 이용 => 보기 좋아
			int subarraySum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];

			//put a check is subarraySum > largest_sum => std::max 함수 이용
			largest_sum = max(largest_sum, subarraySum);
		}
	}
	return largest_sum;
}

// O(n) 으로 largest subarray sum 을 구할 수 있다
int kadanesAlgorithm(int arr[], int n) {

	int cs = 0; // current sum
	int largest = 0;

	// 전체 배열을 한 번만 돈다
	for (int i = 0; i < n; i++) {

		// 현재까지 구간 합을 구한다 => 즉 현재 값을 포함하도록 구간 갱신
		cs = cs + arr[i];
		largest = max(largest, cs); // 최대값 갱신
		/*
			구간 합이 조금 줄어드는 것은 괜찮다, 왜? = 나중에 큰 값이 나오면 다시 최고 합을 만들 수 있으니까
			=> 아직 이 구간을 포함하는 구간에서 최대값이 나올 확률이 있다

			그런데, 현재까지의 합이 마이너스라면 => 이 구간에서는 절대 최대값이 나올 수 없다
			이 구간은 포함하는 순간 무조건 값이 내려가기 떄문에, 이 구간 외에서 무조건 최대값이 나온다
			=> 따라서 구간 합이 마이너스가 되는 순간, 구간을 새로 잡는다
		*/
		if (cs < 0) {
			cs = 0;
		}
	}
	return largest;
}

#include <vector>
// vector 이용 예시
void vectorUse() {
	// vector initialization
	vector<int> arr1 = { 1,2,3 };
	vector<int> arr2{ 4,5,6 };

	// Fill Constructor => 5개 넣는다, 1로
	vector<int> arr3(5, 1);

	arr3.pop_back();
	arr3.push_back(10);
	arr3.emplace_back(20);
	// given iterator 앞에 값을 추가한다
	arr3.emplace(arr3.end(), 30);
	// iterator 이용, 중간에 넣는 것도 가능하네? dynamic array 인데 중간 삽입이 가능하다
	arr3.emplace(arr3.begin() + 1, 800);

	cout << "Size is " << arr3.size() << endl;
	cout << "Capacity is " << arr3.capacity() << endl;

	for (auto x : arr3)
		cout << x << " ";
	cout << endl;
}


int main() {
	vectorUse();
}