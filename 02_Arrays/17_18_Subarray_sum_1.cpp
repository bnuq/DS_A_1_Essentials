#include<iostream>
using namespace std;

//Problem : Print all subarrays of a given array

// 17th.
// Brute Force Approach O(N^3)
int largestSubarraySum1(int arr[],int n){

	int largest_sum = 0;

	for(int i=0;i<n;i++){
		for(int j=i; j<n; j++){

			int subarraySum = 0;

			for(int k=i; k<=j; k++){
				//cout<<arr[k] <<",";
				subarraySum += arr[k];
			}
			//put a check is subarraySum > largest_sum
			// algorithm header 에서 제공하는 max => 더 큰 값을 리턴 => 나도 이용하자
			largest_sum = max(largest_sum,subarraySum);

		}
	}
	return largest_sum;
}



// 18th
// Prefix Sum Approach O(N^2)
// Prefix Sum 이라는 개념이 하나 딱 존재하는거다 => 구간 합, 앞에서부터 현재까지 합
int largestSubarraySum2(int arr[],int n){

	//Prefix Sums
	int prefix[100] = {0};
	prefix[0] = arr[0];
	
	for(int i=1;i<n;i++){
		prefix[i] = prefix[i-1] + arr[i];
	}

	//largest sum login
	int largest_sum = 0;

	for(int i=0;i<n;i++){
		for(int j=i; j<n; j++){

			// 특정 구간 내 합을 구하는 과정을, O(n) 이 아닌 O(1) 로 해결
			// 3중 연산자 이용 => 보기 좋아
			int subarraySum = i>0 ? prefix[j] - prefix[i-1] : prefix[j];
			
			//put a check is subarraySum > largest_sum
			largest_sum = max(largest_sum,subarraySum);

		}
	}
	return largest_sum;
}

int main(){
	//Array Containing 
	int arr[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);

	cout<< largestSubarraySum1(arr,n) <<endl;
	cout<< largestSubarraySum2(arr,n) <<endl;


	return 0;
}