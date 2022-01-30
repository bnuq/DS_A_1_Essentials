
#include<iostream>
using namespace std;

// 함수에서는 배열 원소 개수를 구하기 어렵다 => 인수로 넘겨줌
void printArray(int* arr,int n){

	// 포인터 크기 출력, 주소 크기 출력
	cout <<"In Function "<<sizeof(arr) <<endl;

	arr[0] = 100;
	for(int i=0;i<n;i++){
		cout << arr[i] <<endl; 
	}
}

// non-type template argument 를 이용하면?
template<typename T, int size>
void printArrayRef(T(&arrRef)[size])
{
	arrRef[0] = 100;
	for (int i = 0; i < size; i++) {
		cout << arrRef[i] << endl;
	}
}



int main(){

	int arr[] = {1,2,3,4,5,6};

	// 원소 개수 구함
	int n = sizeof(arr)/sizeof(int);



	// 배열 전체 크기 출력
	cout <<"In Main "<<sizeof(arr) <<endl;

	for(int i=0;i<n;i++){
		cout << arr[i] <<endl; 
	}

	printArray(arr, n);

	printArrayRef(arr);

	return 0;
}