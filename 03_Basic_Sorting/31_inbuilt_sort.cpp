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

	// function pointer �� ���� => sort function ������ ���� �� �ش� �Լ��� ȣ���Ѵ�
	sort(arr, arr + n, compare ); // sort : ���Լ��� �̿��ؼ� �����ϴ� �Լ�
	//reverse(arr, arr + n);	  // reverse : �迭�� ������ �ִ� �Լ�

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