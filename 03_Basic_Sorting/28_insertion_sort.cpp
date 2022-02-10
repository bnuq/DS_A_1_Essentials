#include<iostream>
using namespace std;

//Sort the elements in increasing order 
// ī�带 ���徿 �߰��ϸ鼭 �����Ѵ�
// �ڿ��� �ϳ��� �߰�, ������ ��ġ�� ã�� �ִ´�
void insertion_sort(int a[],int n){

	for(int i=1; i<=n-1; i++){

		int current = a[i];

		int prev = i - 1; 

		//loop to find the right index where the element current should be inserted
		// and Ű���� ����
		// previous �� ���鼭, ���� ���� ���� ��ġ�� ã�´�
		while(prev>=0 and a[prev] > current){
			a[prev + 1] = a[prev];
			prev = prev - 1;
		}

		a[prev+1] = current; 
	}


}


int main(){
	int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);
	insertion_sort(arr,n);

	for(auto x : arr){
		cout << x  <<",";
	}

	return 0;
}