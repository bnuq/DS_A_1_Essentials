/*
	그래프를 그려서 확인
	반복문에서도 조사하는 범위를 조금씩 줄여나가는 방식 = Divide
	줄인 범위에 대해서 작업 = Conquer
*/
#include<iostream>
#include<vector>
using namespace std;


/*
	배열을 넘어서 한바퀴 도는 숫자 배열이 있을 때, key 가 위치한 인덱스는?
	이 문제의 경우, 재귀 없이 문제를 풀었지만 반복문 내에서
	먼저 이번 단계 작업을 진행하고 => mid 에 key 값이 존재하는 지 확인
	이후 구간을 줄어나가는 작업을 진행 => key 가 위치할 구간을 계산해서 검색 범위를 좁힌다
	그래서 Divide and Conquer 이다
*/
int rotated_search(vector<int> a,int key) {
	int n = a.size(); // 전체 개수

	// 검색 구간 인덱스 => 처음부터 끝 사이
	int s = 0;
	int e = n - 1;

	while(s<=e){
		int mid = (s+e)/2; // 중간 인덱스에 대해서

		if(a[mid]==key){	// 중간에 있거나
			return mid;
		}

		// 중간에 값의 최소값과 최고값이 서로 만나지만, 어쨌든 한바퀴 돌아서 정렬되어 있다는 걸 이용
		if(a[s]<=a[mid]){ // 최고값이 나오기 전 구간에 mid 가 있는 경우
			//left
			if(key>=a[s] and key<=a[mid]){ // key 가 위치한 구간을 다시 찾는다
				e = mid - 1;
			}
			else{
				s = mid + 1;
			}

		}
		else{ // 최소값 이후 구간에 mid 가 있는 경우
			//right
			if(key>=a[mid] and key<=a[e]){ // 역시 key 가 위치한 구간을 다시 찾는다
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