#include<iostream>
using namespace std;


// O(n)
int maximum_subarray_sum(int arr[],int n){

	int cs = 0;
	int largest = 0;

	
	// 전체 배열을 한 번만 돈다
	for(int i=0;i<n;i++){

		// 현재까지 구간 합을 구하는데
		cs = cs + arr[i];

		/*
			구간 합이 조금 줄어드는 것은 괜찮다
			현재 구간 내에서 어쨌든 최고 합이 존재하고
			나중에 큰 값이 나오면 다시 최고 합을 만들 수 있으니까
			=> 아직 이 구간에서 최대값이 나올 확률이 있다
			
			근데 구간 합이 마이너스가 나온다면?
			이 구간에서 나올 수 있는 최대 값은 이미 나왔다~
			만약 뒤에서 다시 최고 값이 나온다면 => 그 구간에서만 최대 값을 구하면 더 큰 값이 나온다
			=> 따라서 구간 합이 마이너스가 되는 순간, 구간을 새로 잡는다

			0 이 기준인 이유 = 처음 시작 값
			처음 시작보다 더 떨어졌다면,
			구간을 새로 잡고 다시 0부터 시작하는 게 좋다
		*/
		if(cs < 0){
			cs = 0;
		}
		largest = max(largest, cs);
	}

	return largest;
}


int main(){
	//Array Containing 
	int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);

	cout<< maximum_subarray_sum(arr,n) <<endl;

	return 0;
}