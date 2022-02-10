#include<iostream>
#include<algorithm>
using namespace std;



bool compare(int a,int b){
	//cout<<"Comparing "<<a <<" and "<<b <<endl;
	return a < b;
}


int main(){

	int arr[] = {10,9,8,6,5,4,3,2,11,16,8};
	int n = sizeof(arr)/sizeof(int);

	// function pointer 로 전달 => sort function 내에서 비교할 떄 해당 함수를 호출한다
	sort(arr, arr + n, compare ); // sort : 비교함수를 이용해서 정렬하는 함수
	//reverse(arr, arr + n);	  // reverse : 배열을 뒤집어 주는 함수

	//Print the ouput
	for(int x : arr){
		cout<< x <<" ";
	}
	cout << endl << endl;

	// Lambda expression
	sort(arr, arr + n, [](const auto& e1, const auto& e2) {
		return e1 > e2;
		});

	//Print the ouput
	for (int x : arr) {
		cout << x << " ";
	}

	return 0;
}