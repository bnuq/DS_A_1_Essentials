#include <iostream>
#include <vector>
using namespace std;


/*
	Main Problem = Recursive Case + Base Case
	하나의 큰 문제를 동일하지만 크기만 작은 문제로 나눌 수 있다
	크기가 작은 문제로 나누는 과정 = Recursive Case
	더이상 나눌 수 없는 작은 문제를 해결하는 과정 = Base Case
	sub problem 이 해결됐다고 가정하고, 해결된 subproblem 을 기반으로 big problem 을 해결한다
*/


/*
	sub problem 을 해결하고 나서 => 현재 단계를 해결하느냐,
	현재 단계를 해결하고 나서 => sub problem 을 해결하느냐 에 따라
	작업의 순서가 완전히 반대가 된다, 그러니까 원하는 순서를 잘 파악하는 것이 중요하다
*/
void dec(int n) { // decrasing order 로 숫자를 출력
	//base case
	if (n == 0) {
		return;
	}
	//towards the base case
	cout << n << ","; // 먼저 가장 높은 현재 단계를 출력하고 나서 ~
	dec(n - 1);	   // sub problem 해결 => 밑의 숫자 출력
}
void inc(int n) { // increasing order 로 출력
	//base case
	if (n == 0) {
		return;
	}
	inc(n - 1);		// sub problem 을 먼저 해결한다 == 앞의 것을 먼저 출력하고 나서
	cout << n << ",";	// 이번 단계 작업을 진행한다
}


/*
	first occurence, last occurence 를 찾는 문제 => 현재 단계 해결과 sub problem 해결에 대해서, 순서를 어떻게 설정하느냐가 중요하다
	두 문제 다 배열의 앞부분->뒷부분 순서로 recursion 을 진행할 때,
	For first occurence => 앞 부분에 있는 것을 찾아야 한다 => 먼저 현재 단계 작업을 진행하고, 찾지 못한 경우 뒤의 sub problem 을 진행한다
	For last occurence => 뒷 부분에 있는 것을 찾아야 한다 => 뒤에 위치한 sub problem 에서 값을 찾았는 지 먼저 확인한다. 뒤에서 찾이 못한 경우, 현재 단계 작업을 진행한다
	Recursion 에서는 현재 단계 작업과 sub problem 작업 중, 무엇을 먼저할 지 순서를 설정하는 게 매우매우 중요하다
*/
int firstOcc(int arr[], int n, int key) {
	// base case
	if (n == 0) {
		return -1;
	}

	if (arr[0] == key) { // 현재 단계 작업 먼저 하고 => 항상 주어진 배열의 첫번째 요소를 체크한다
		return 0;
	}
	// 이후에 sub problem 풀기
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

	// sub problem 먼저 해결하고 나서
	int subIndex = lastOcc(arr + 1, n - 1, key);
	if (subIndex == -1) { // sub problem 을 해결하지 못했을 때
		// 현재 단계 작업 하기
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
	a^n 구하기
	Space ~ O(log n), Time ~ O(log n)
	a^n 을 구하기 위해서, 먼저 sub problem => a^n/2 를 구한다, 그리고 그 결과를 이용해서 a^n 을 구한다
	이때 n 이 홀수냐 짝수냐에 따라 조금씩 현재 단계 작업이 달라진다
*/
int fastPower(int a, int n) {
	if (n == 0) {	// Base Case, A^0 = 무조건 1
		return 1;
	}

	// sub problem 을 먼저 해결한다
	int subProb = fastPower(a, n / 2);		// Recursive Case
	int subProbSq = subProb * subProb;
	if (n & 1) { // 현재 n 이 홀수라면
		return a * subProbSq; // a 를 추가로 곱해준다 
	}
	return subProbSq;
}


// Bubble Sort 를 반복문 => Recursion 으로 표현
// 전체 범위를 조정하는, Outer loop 만 반영
void bubble_sort_rec(int a[], int n) {
	//base case
	if (n == 1) {
		return;
	}

	// 기존 내부 루프문은 그대로 유지
	// 현재 단계 작업을 먼저 진행하고
	for (int j = 0; j < n - 1; j++) {
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}

	// Sub Problem => 마지막 범위만 줄였다
	bubble_sort_rec(a, n - 1);
}
// Outer, Inner loop 모두 수정
// 2중 루프문을 하나의 Recursion function 으로 대체할 수 있다
void bubble_sort_rec_2(int a[], int n, int j) { // n 개에 대해서 진행, 현재 j 인덱스 위치
	//base case, 끝 범위가 1 이하면 종료
	if (n == 1 || n == 0) {
		return;
	}

	if (j == n - 1) { // 마지막 요소에 도착 => Outer Loop 를 바꾸어 주어야 한다
		//reduce the problem size, and reset j to 0
		bubble_sort_rec_2(a, n - 1, 0); // 다시 0번째 부터 시작
		return;
	}

	// j 번째와 j+1 번째 비교 => 정렬
	if (a[j] > a[j + 1]) {
		swap(a[j], a[j + 1]);
	}

	// 다음 인덱스로 넘어감 = sub problem
	bubble_sort_rec_2(a, n, j + 1);
}


/*
	주어진 숫자를 string 표현으로 바꾸기
	숫자는 1 의 자리부터 빼내는 것이 편하고, 읽기에는 높은 자리부터 읽어내는 것이 편하다 => 방향이 완전 반대
	Recursion 을 이용 => 이번 단계에서 1 의 자리부터 읽어내지만, sub problem 을 먼저 풀면 높은 자리부터 처리를 할 수 있다
	이런 판단이 진짜 어려운 거 같애
*/
string spell[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
void printSpell(int n) {
	if (n == 0) { // 더이상 읽을 숫자가 없다
		return;
	}
	int last_digit = n % 10; // 이번 단계의 마지막 숫자를 일단 빼내고
	printSpell(n / 10);	   // sub problem 먼저 해결 => 높은 자리 숫자들을 먼저 출력한 다음에
	cout << spell[last_digit] << " "; // 이번 단계 숫자 출력
}