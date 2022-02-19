#include <iostream>
using namespace std;

/*
* Bubble Sort
* ó������ ������ �����ϴ� ���� �ݺ�, �� ���縶�� ��ǰ�� �ö���� ��ó�� ���� ū ���� �ڷ� ������
* �̹��� ������ ��, ������ �� ������ swap �� �Ѵ�
*/
void bubble_sort(int a[], int n) {
	// �� ���� - 1 �� �ݺ��Ѵ�
	for (int times = 1; times <= n - 1; times++) {
		//repeated swapping
		// ó������ �� ���ұ��� �����Ѵ�, �� �ݺ����� ���������� ���ʴ�� ���ĵȴ�
		// �߰��� swap �ϴ� ��찡 ��� ������� => �ᱹ ���� ū ���� �����ϱ�
		for (int j = 0; j <= n - times - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]); // swap �Լ� �ֿ�
			}
		}

	}
}

/*
* Insertion Sort
* �տ��� ī�带 �����ϴ� ����� �����ϰ� ����
* ���ʿ� �ִ� ī����� ���� => ���� �������� ī�带 �߰�, ���ĵ� �и� �ø���
* �����ʿ� �ִ� ī�带 �߰��� ������ ��ġ�� �Ⱦ� �ִ´�
*/
void insertion_sort(int a[], int n) {
	for (int i = 1; i <= n - 1; i++) {
		int current = a[i]; // �����ϰ��� �ϴ� ī��
		int prev = i - 1; // �������� ��ġ �� ��ġ��, �ε����� ���� ��Ÿ����
		// loop to find the right index where the element current should be inserted
		// �� ��ġ ������ ���鼭, ���� �ְ��� �ϴ� ��ġ�� �ľ��Ѵ�
		while (prev >= 0 and a[prev] > current) {
			a[prev + 1] = a[prev]; // �� ���� => ī���� �̵��� �ǹ�
			prev = prev - 1;
		}
		a[prev + 1] = current;
	}
}

/*
* Selection Sort
* ���ĵ��� ���� �������� ���� ���� ���� ã�Ƽ� ������ ~
* ���ʿ������� �����Ѵ�
*/
void selection_sort(int a[], int n) {
	// pos = �̹��� ���� �ְ��� �ϴ� ��ġ
	for (int pos = 0; pos < n - 1; pos++) {
		int current = a[pos];
		int min_position = pos; // �ϴ� ���� ���� �ּ� ���̶� �����ϰ�
		//find out the element 
		for (int j = pos+1; j < n; j++) {
			if (a[j] < a[min_position]) {
				min_position = j; // ���� ���� ���� �ִ� ��ġ�� �����´�
			}
		}
		// swap outside the loop
		// swap �� ���ؼ�, ���� ���� ���� ������ �����´�
		swap(a[min_position], a[pos]);
	}
}

/*
* <algorithm> :: sort() => �����ϰ� ������ �����ϴ�
* <algorithm> :: reverse() => container element ������ �Ųٷ� �����Ѵ�
* ���ϴ� ��� ���� ���� => comparator ����
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

	sort(arr, arr + n); // �⺻�����δ� non-decreasing order �� �����Ѵ�

	// function pointer �� ���� => sort function ������ ���� �� �ش� �Լ��� ȣ���Ѵ�
	sort(arr, arr + n, compare); // sort : ���Լ��� �̿��ؼ� �����ϴ� �Լ�
	
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

	reverse(arr, arr + n);	  // reverse : �迭�� ������ �ִ� �Լ�
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl << endl;


	// ���������� �̹� ���ǵ� competitor => bool return �ϱ� ������ predicate �� �θ���
	// function object �ε�?
	sort(arr, arr + n, greater<int>()); // ū ���� ���ʿ� �´�
	sort(arr, arr + n, less<int>()); // ���� ���� ���ʿ� �´�
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl << endl;
}

/*
* Counting Sort ~ O(range + n)
* ������ ���� ������ �����Ǿ� ���� �� ���, ���� ������ŭ ���̸� ������ �迭 frequency vector �̿�
* � ���� �����ϸ�, �� ���� �ε����� ~ �迭�� ���� ������Ų��
* ���� frequency vector �� ���� �������� �ľ��Ѵ�
*/
#include <vector>
void counting_sort(int a[], int n) {
	//Largest Element
	int largest = -1;
	for (int i = 0; i < n; i++) {
		largest = max(largest, a[i]); // �ִ밪 => ���� ������ �˾Ƴ���
	}
	//create a count array/vector
	vector<int> freq(largest + 1, 0); // fill constructor
	//Update the freq array 
	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
	}
	//Put back the elements from freq into original array
	int j = 0; // original vector �� �ִ� �ε���
	for (int i = 0; i <= largest; i++) { // freq vector �� ����
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