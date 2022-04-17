#include <iostream>
#include <vector>

using namespace std;


/* 
	LIS = Longest Increasing Subsequence
	
	주어진 배열에서, 해당 원소를 끝에 두면서
	오름차순으로 나열할 수 있는 원소들의 최대길이

	임의의 배열 원소까지 최대 길이를 저장해둔다

	다음 원소는 자신이 위치할 수 있는, 자신이 제일 크게 위치할 수 있는 배열들 중
	가장 길이가 긴 것을 선택하고, 자신이 그 뒤에 가면 => LIS
 */
// Bottom Up Solution
int lis(vector<int> arr) {
	int n = arr.size();

	// 만약 해당 원소가 가장 작은 값이면 해당 값만 포함 => 길이 1
	vector<int> dp(n, 1);

	// 0 번째 원소 혼자 있으면, 그것 혼자서 lis 를 구성
	// 최소 1의 길이를 가진다
	int len = 1;

	// 1 번째 원소부터 조사 시작
	for(int i = 1; i < n; i++) {
		// 자신의 앞에 있는 원소들을 조사
		for(int j = 0; j < i; j++) {

			// 현재 원소가 가장 마지막에 위치할 수 있다
			if(arr[i] > arr[j]) {
				// 현재 값 하고 후보 값을 비교 => 더 큰 값을 현재 값으로 갱신한다
				dp[i] = max(dp[i], 1 + dp[j]);
				len = max(len, dp[i]);
			}
		}
	}

	return len;
}


int main() {
	vector<int> arr{50, 4, 10, 8, 30, 100};
	cout << lis(arr) << endl;
}