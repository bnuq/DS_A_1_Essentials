#include <iostream>
#include <vector>
using namespace std;


/*
	Main Problem = Recursive Case + Base Case
	�ϳ��� ū ������ ���������� ũ�⸸ ���� ������ ���� �� �ִ�
	ũ�Ⱑ ���� ������ ������ ���� = Recursive Case
	���̻� ���� �� ���� ���� ������ �ذ��ϴ� ���� = Base Case
	sub problem �� �ذ�ƴٰ� �����ϰ�, �ذ�� subproblem �� ������� big problem �� �ذ��Ѵ�
*/


/*
	sub problem �� �ذ��ϰ� ���� => ���� �ܰ踦 �ذ��ϴ���,
	���� �ܰ踦 �ذ��ϰ� ���� => sub problem �� �ذ��ϴ��� �� ����
	�۾��� ������ ������ �ݴ밡 �ȴ�, �׷��ϱ� ���ϴ� ������ �� �ľ��ϴ� ���� �߿��ϴ�
*/
void dec(int n) { // decrasing order �� ���ڸ� ���
	//base case
	if (n == 0) {
		return;
	}
	//towards the base case
	cout << n << ","; // ���� ���� ���� ���� �ܰ踦 ����ϰ� ���� ~
	dec(n - 1);	   // sub problem �ذ� => ���� ���� ���
}
void inc(int n) { // increasing order �� ���
	//base case
	if (n == 0) {
		return;
	}
	inc(n - 1);		// sub problem �� ���� �ذ��Ѵ� == ���� ���� ���� ����ϰ� ����
	cout << n << ",";	// �̹� �ܰ� �۾��� �����Ѵ�
}


/*
	first occurence, last occurence �� ã�� ���� => ���� �ܰ� �ذ�� sub problem �ذῡ ���ؼ�, ������ ��� �����ϴ��İ� �߿��ϴ�
	�� ���� �� �迭�� �պκ�->�޺κ� ������ recursion �� ������ ��,
	For first occurence => �� �κп� �ִ� ���� ã�ƾ� �Ѵ� => ���� ���� �ܰ� �۾��� �����ϰ�, ã�� ���� ��� ���� sub problem �� �����Ѵ�
	For last occurence => �� �κп� �ִ� ���� ã�ƾ� �Ѵ� => �ڿ� ��ġ�� sub problem ���� ���� ã�Ҵ� �� ���� Ȯ���Ѵ�. �ڿ��� ã�� ���� ���, ���� �ܰ� �۾��� �����Ѵ�
	Recursion ������ ���� �ܰ� �۾��� sub problem �۾� ��, ������ ������ �� ������ �����ϴ� �� �ſ�ſ� �߿��ϴ�
*/
int firstOcc(int arr[], int n, int key) {
	// base case
	if (n == 0) {
		return -1;
	}

	if (arr[0] == key) { // ���� �ܰ� �۾� ���� �ϰ� => �׻� �־��� �迭�� ù��° ��Ҹ� üũ�Ѵ�
		return 0;
	}
	// ���Ŀ� sub problem Ǯ��
	int subIndex = firstOcc(arr + 1, n - 1, key);
	if (subIndex != -1) {
		return subIndex + 1;
	}
	return -1;
}
int lastOcc(int arr[], int n, int key) {
	//base case
	if (n == 0) {
		return -1;
	}

	// sub problem ���� �ذ��ϰ� ����
	int subIndex = lastOcc(arr + 1, n - 1, key);
	if (subIndex == -1) { // sub problem �� �ذ����� ������ ��
		// ���� �ܰ� �۾� �ϱ�
		if (arr[0] == key) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		return subIndex + 1;
	}
}


/*
	a^n ���ϱ�
	Space ~ O(log n), Time ~ O(log n)
	a^n �� ���ϱ� ���ؼ�, ���� sub problem => a^n/2 �� ���Ѵ�, �׸��� �� ����� �̿��ؼ� a^n �� ���Ѵ�
	�̶� n �� Ȧ���� ¦���Ŀ� ���� ���ݾ� ���� �ܰ� �۾��� �޶�����
*/
int fastPower(int a, int n) {
	if (n == 0) {	// Base Case, A^0 = ������ 1
		return 1;
	}

	// sub problem �� ���� �ذ��Ѵ�
	int subProb = fastPower(a, n / 2);		// Recursive Case
	int subProbSq = subProb * subProb;
	if (n & 1) { // ���� n �� Ȧ�����
		return a * subProbSq; // a �� �߰��� �����ش� 
	}
	return subProbSq;
}


// Bubble Sort �� �ݺ��� => Recursion ���� ǥ��
// ��ü ������ �����ϴ�, Outer loop �� �ݿ�
void bubble_sort_rec(int a[], int n) {
	//base case
	if (n == 1) {
		return;
	}

	// ���� ���� �������� �״�� ����
	// ���� �ܰ� �۾��� ���� �����ϰ�
	for (int j = 0; j < n - 1; j++) {
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}

	// Sub Problem => ������ ������ �ٿ���
	bubble_sort_rec(a, n - 1);
}
// Outer, Inner loop ��� ����
// 2�� �������� �ϳ��� Recursion function ���� ��ü�� �� �ִ�
void bubble_sort_rec_2(int a[], int n, int j) { // n ���� ���ؼ� ����, ���� j �ε��� ��ġ
	//base case, �� ������ 1 ���ϸ� ����
	if (n == 1 || n == 0) {
		return;
	}

	if (j == n - 1) { // ������ ��ҿ� ���� => Outer Loop �� �ٲپ� �־�� �Ѵ�
		//reduce the problem size, and reset j to 0
		bubble_sort_rec_2(a, n - 1, 0); // �ٽ� 0��° ���� ����
		return;
	}

	// j ��°�� j+1 ��° �� => ����
	if (a[j] > a[j + 1]) {
		swap(a[j], a[j + 1]);
	}

	// ���� �ε����� �Ѿ = sub problem
	bubble_sort_rec_2(a, n, j + 1);
}


/*
	�־��� ���ڸ� string ǥ������ �ٲٱ�
	���ڴ� 1 �� �ڸ����� ������ ���� ���ϰ�, �б⿡�� ���� �ڸ����� �о�� ���� ���ϴ� => ������ ���� �ݴ�
	Recursion �� �̿� => �̹� �ܰ迡�� 1 �� �ڸ����� �о����, sub problem �� ���� Ǯ�� ���� �ڸ����� ó���� �� �� �ִ�
	�̷� �Ǵ��� ��¥ ����� �� ����
*/
string spell[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
void printSpell(int n) {
	if (n == 0) { // ���̻� ���� ���ڰ� ����
		return;
	}
	int last_digit = n % 10; // �̹� �ܰ��� ������ ���ڸ� �ϴ� ������
	printSpell(n / 10);	   // sub problem ���� �ذ� => ���� �ڸ� ���ڵ��� ���� ����� ������
	cout << spell[last_digit] << " "; // �̹� �ܰ� ���� ���
}