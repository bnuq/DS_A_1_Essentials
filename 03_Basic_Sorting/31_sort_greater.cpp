#include<iostream>
#include<algorithm>
using namespace std;




int main(){

	int arr[] = {10,9,8,6,5,4,3,2,11,16,8};
	int n = sizeof(arr)/sizeof(int);

	// inbuilt competitor, predicate
	// function object ¿ŒµÌ?
	sort(arr, arr + n, greater<int>());
	sort(arr, arr + n, less<int>());
	//reverse(arr, arr + n);

	//Print the ouput
	for(int x : arr){
		cout<< x <<" ";
	}


	return 0;
}