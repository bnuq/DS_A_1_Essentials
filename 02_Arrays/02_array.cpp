#include<iostream>
using namespace std;

/*
* non-type template argument ���� size �� �� �ִ�
* array reference �� size ������ ����ִ�
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
	// �ʱ�ȭ ����, ���� �� ������ 0���� �ʱ�ȭ
	int marks[100]{ -1 };
	for (int i = 0; i < 100; i++) {
		cout << marks[i] << " ,";
	}

	/*
	* C-Style Array ��� = pointer ��� => �ּҸ� �̿�
	* �׷��� array size �� �� �� ���� => ������ ���� �Ѱ��־�� �Ѵ�
	* �ƴϸ� ���� ���ϱ�
	*/
	int n = sizeof(marks) / sizeof(int); // ���� ����, 100 ���
	sizeof(marks); // = �迭 ��ü ũ��

	printArrayRef(marks);
}

/*
* linear search
* �׳� ó������ ������ ������� ã�� ��
* O(n)
*/
int linear_search(int arr[], int n, int key) {
	// �׳� ��ü �迭�� �����鼭 ã��
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
* �̹� ���ĵ� �迭 => ������ �ݾ� �������鼭 ã��
*/
int binary_search(int arr[], int n, int key) {
	// �˻� ������ ��Ÿ���� �ε��� => �ε����� ����ϴ� ����� ���� ������
	// ����� �žƵδ� ����?
	int s = 0;
	int e = n - 1;
	
	// �˻� ������ ������ => ���� ��߳� �� ���� �ݺ��ϴ� ��
	while (s <= e) {
		int mid = (s + e) / 2; // �߰�����

		if (arr[mid] == key) {
			return mid;
		}

		// �˻� ������ �����Ѵ�
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
* Problem : Ư�� �迭 ���ҵ��� ������ ������ �ʹ�
* Brute Force �ϰ� �����ϸ�..? => �迭�� �ڿ������� ���� ����, �������� �迭�� �����
* or ���� �����ߴ� in-place algorithm => temp ������ 2�� �����, �ϳ��� �ӽ������ϰ� �ű�� �ٽ� �ӽ������ϰ�... �ݺ�
* �ٵ� �������� �� �����ϰ� �ذ� => swap
	* Ư�� �޸� ������ ����ų�, ���� �Ϸķ� �־������ �ذ����� �ʰ�
	* �� �ڸ� �������ָ�, ��������� �������� ����� ���´� ~
	* ���� ������ ���ʹ������� �����ϰ� �̵��ϴ� �� ����, swap �ϴ� ��츦 �����غ����� ����
*/
void reverseArray(int arr[], int n) {

	int s = 0;
	int e = n - 1;

	// ������ �ٿ����鼭, �� �ڸ� ���� �ٲ��ش�
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
	// i = ���� ����, j = �� ����, k = subarray element
	// �ݺ��� ��, �� ������ ������ ���ϴ� �� Ȯ���� �ľ�����
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int subarraySum = 0;
			for (int k = i; k <= j; k++) {
				subarraySum += arr[k];
			}
			//put a check is subarraySum > largest_sum
			// algorithm header ���� �����ϴ� max => �� ū ���� ���� => ���� �̿�����
			largest_sum = max(largest_sum, subarraySum);
		}
	}
	return largest_sum;
}

/*
* Prefix Sum Approach O(N^2)
* Prefix Sum �̶�� ���� => ���� ��, �տ������� ������� ��
* �̸� ����� ������ Ư�� ������ ���� ���� ���� �� �ִ�
*/
int largestSubarraySum2(int arr[], int n) {

	int prefix[100] = { 0 };
	prefix[0] = arr[0];

	// prefix sum �� ���ϴ� ���� => �տ������� �������� ���Ѵ�	
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	int largest_sum = 0;

	for (int i = 0; i < n; i++) { // ������ ��� sub array �� ���Ͽ�
		for (int j = i; j < n; j++) {
			// Ư�� ���� �� ���� ���ϴ� ������, O(n) �� �ƴ� O(1) �� �ذ�
			// 3�� ������ �̿� => ���� ����
			int subarraySum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];

			//put a check is subarraySum > largest_sum => std::max �Լ� �̿�
			largest_sum = max(largest_sum, subarraySum);
		}
	}
	return largest_sum;
}

// O(n) ���� largest subarray sum �� ���� �� �ִ�
int kadanesAlgorithm(int arr[], int n) {

	int cs = 0; // current sum
	int largest = 0;

	// ��ü �迭�� �� ���� ����
	for (int i = 0; i < n; i++) {

		// ������� ���� ���� ���Ѵ� => �� ���� ���� �����ϵ��� ���� ����
		cs = cs + arr[i];
		largest = max(largest, cs); // �ִ밪 ����
		/*
			���� ���� ���� �پ��� ���� ������, ��? = ���߿� ū ���� ������ �ٽ� �ְ� ���� ���� �� �����ϱ�
			=> ���� �� ������ �����ϴ� �������� �ִ밪�� ���� Ȯ���� �ִ�

			�׷���, ��������� ���� ���̳ʽ���� => �� ���������� ���� �ִ밪�� ���� �� ����
			�� ������ �����ϴ� ���� ������ ���� �������� ������, �� ���� �ܿ��� ������ �ִ밪�� ���´�
			=> ���� ���� ���� ���̳ʽ��� �Ǵ� ����, ������ ���� ��´�
		*/
		if (cs < 0) {
			cs = 0;
		}
	}
	return largest;
}

#include <vector>
// vector �̿� ����
void vectorUse() {
	// vector initialization
	vector<int> arr1 = { 1,2,3 };
	vector<int> arr2{ 4,5,6 };

	// Fill Constructor => 5�� �ִ´�, 1��
	vector<int> arr3(5, 1);

	arr3.pop_back();
	arr3.push_back(10);
	arr3.emplace_back(20);
	// given iterator �տ� ���� �߰��Ѵ�
	arr3.emplace(arr3.end(), 30);
	// iterator �̿�, �߰��� �ִ� �͵� �����ϳ�? dynamic array �ε� �߰� ������ �����ϴ�
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