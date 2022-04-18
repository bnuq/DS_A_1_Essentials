#include<iostream>
#include <vector>
using namespace std;


// 전체 구간을 정렬하면서 합치는
void merge(vector<int> &array,int s,int e){ // s ~ e 사이 정렬
	int i = s;			// i ~ m 구간
	int m = (s+e)/2;
	int j = m + 1;		// j ~ e 구간

	vector<int> temp;
	while(i<=m and j<=e){ // 각 구간에 대해서
		if(array[i] < array[j]){
			temp.push_back(array[i]);
			i++;
		}
		else{
			temp.push_back(array[j]);
			j++;
		}
	}
	// 남은 거 전부 넣기
	//copy rem elements from first array
	while(i<=m){
		temp.push_back(array[i++]);
	}
	// or copy rem elements from second array
	while(j<=e){
		temp.push_back(array[j++]);
	}
	// 정렬했던 것 array 에 넣기
	//copy back the eleemtns from temp to original array
	int k = 0 ;
	for(int idx = s; idx <=e ;idx++){
		array[idx] = temp[k++];
	}
	return;
}

//sorting method
void mergesort(vector<int> &arr,int s,int e){
	//base case
	if(s>=e){
		return; // 요소가 하나만 남아 => 더이상 나눌 수 없다
	}
	//rec case
	int mid = (s+e)/2;		// 중간 인덱스를 기준으로
	// 하나의 큰 문제를 2 개의 sub problems 로 나눈다 => 일단 나누니까, Divide
	mergesort(arr,s,mid);
	mergesort(arr,mid+1,e);
	// 문제를 나누고 나서, 해결을 하면서 => 다시 big problem 으로 돌아간다, Conquer
	// 현재 단계 문제 해결을 진행한다
	return merge(arr,s,e); // 나눈 문제를 합치면서 종료
}

int main(){
  	
  	vector<int> arr{10,5,2,0,7,6,4};

	int s = 0;
	int e = arr.size()-1;
  	mergesort(arr,s,e);
	for(int x : arr){
		cout<< x <<",";
	}
	cout<<endl;
	return 0;
}




