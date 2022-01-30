
#include<iostream>
using namespace std;

// �Լ������� �迭 ���� ������ ���ϱ� ��ƴ� => �μ��� �Ѱ���
void printArray(int* arr,int n){

	// ������ ũ�� ���, �ּ� ũ�� ���
	cout <<"In Function "<<sizeof(arr) <<endl;

	arr[0] = 100;
	for(int i=0;i<n;i++){
		cout << arr[i] <<endl; 
	}
}

// non-type template argument �� �̿��ϸ�?
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

	// ���� ���� ����
	int n = sizeof(arr)/sizeof(int);



	// �迭 ��ü ũ�� ���
	cout <<"In Main "<<sizeof(arr) <<endl;

	for(int i=0;i<n;i++){
		cout << arr[i] <<endl; 
	}

	printArray(arr, n);

	printArrayRef(arr);

	return 0;
}