/*
	항상 가장 마지막에 있는 값을 pivot 으로 설정한다
	pivot 값을 기준으로 작은 값들과 큰 값들을 나눈다 => Divide, Sub Problem 으로 나누기
	각각의 영역을 정렬한다 => Conquer, 현재 단계 해결
*/
#include<iostream>
#include <vector>
using namespace std;


int partition(vector<int> &a,int s,int e){ // 구간 s~e 을 정렬한다
	int pivot = a[e];	// 끝에 있는 값을 pivot 으로
	int i = s - 1;		// pivot 보다 큰 값의 왼쪽에 위치하는 인덱스
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
	swap(a[i+1],a[e]); // 마지막에 pivot 이 가운데에 위치하도록 한다
	return i + 1;	   // pivot 의 인덱스 리턴	
}


void quicksort(vector<int> &a, int s,int e){
	//Base Case
	if(s>=e){
		return; // 더이상 나눌 수 없을 때
	}
	//Rec Case
	// 현재 단계에서 작업을 먼저 시행 => pivot 을 중심으로 나누는 작업을 먼저 하고
	// 이게 실질적으로 정렬을 하는 과정인거고
	int p = partition(a,s,e);
	
	// 그 다음 sub problems 로 나누는 작업을 진행한다
	// 이건 사실상 그냥 범위 줄이기만 하는 거지
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
