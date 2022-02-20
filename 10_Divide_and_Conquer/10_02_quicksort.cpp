/*
항상 가장 마지막에 있는 값을 pivot 으로 설정한다
pivot 값을 기준으로 작은 값들과 큰 값들을 나눈다 => Divide
각각의 영역을 정렬한다 => Conquer
*/
#include<iostream>
#include <vector>
using namespace std;


int partition(vector<int> &a,int s,int e){

	int pivot = a[e];
	int i = s - 1;

	/*
	pivot 보다 작은 값, 큰 값을 모으는 작업을 하는데 있어, 어떤 다른 자료구조를 이용하지 않았다
	위치 인덱스와 swap 을 이용해서 구현해냈다
	*/
	for(int j=s;j<e;j++){
		if(a[j] < pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	
	swap(a[i+1],a[e]);
	return i + 1;
	
}

void quicksort(vector<int> &a, int s,int e){
	//Base Case
	if(s>=e){
		return;
	}
	//Rec Case
	int p = partition(a,s,e); // Divide 한 후, pivot 의 위치 인덱스를 리턴
	quicksort(a,s,p-1);
	quicksort(a,p+1,e);
}


int main(){
    vector<int> arr{10,5,2,0,7,6,4};
    cout<< arr.size() <<endl;
    int n = arr.size();

    quicksort(arr,0,n-1);

    for(int x :arr){
    	cout << x << " ";
    }

    return 0;
}
