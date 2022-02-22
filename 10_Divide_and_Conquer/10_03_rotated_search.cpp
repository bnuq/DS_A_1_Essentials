/*
그래프를 그려서 확인
반복문에서도 조사하는 범위를 조금씩 줄여나가는 방식 = Divide
줄인 범위에 대해서 작업 = Conquer*/
#include<iostream>
#include<vector>
using namespace std;

int rotated_search(vector<int> a,int key) {
	int n = a.size();

	//Logic
	int s = 0;
	int e = n - 1;

	while(s<=e){
		int mid = (s+e)/2;

		if(a[mid]==key){
			return mid;
		}

		//2 cases
		if(a[s]<=a[mid]){
			//left
			if(key>=a[s] and key<=a[mid]){
				e = mid - 1;
			}
			else{
				s = mid + 1;
			}

		}
		else{
			//right

			if(key>=a[mid] and key<=a[e]){
				s = mid + 1;
			}
			else{
				e = mid - 1;
			}

		}

	}
	return -1;

}



int main() {

	
	vector<int> a{4,5,6,7,0,1,2,3};
	int key;
	cin>>key;
	cout<< rotated_search(a,key) <<endl;
	return 0;
}