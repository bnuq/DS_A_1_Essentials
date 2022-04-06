#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//k 를 만드는, 가장 긴 sub array 를 만들자
int longestSubarrayKSum(vector<int> arr, int k) {
	
	int n = arr.size(); //vector size

	//인덱스 i 까지의 prefix sum 을 저장한다
	//{prefix sum, 그걸 만드는 인덱스 i} 저장
	unordered_map<int, int> m{};
	
	
	int pre = 0; //prefix sum
	int len = 0; //k 를 만드는 최대 길이


	//주어진 vector 전체 요소를 한번 훓는다
	for (int i = 0; i < n; i++) {
		
		//prefix sum, 앞부분에서 현재 위치 까지의 총 합
		pre += arr[i];

		if (pre == k) { //현재 prefix sum 이 원하는 값이 됐다
			
			//최대 길이 값 갱신 => 기존 길이 값 or 현재 인덱스 까지 길이?
			len = max(len, i + 1);
		}
		/*
			현재 prefix sum 이 원하는 값이 아닌 경우 중,

			prefix sum > k
			prefix sum < k

			prefix sum 은 0 ~ i 까지의 합이니까, 중간에 j ~ i 의 합을 구하면
			원하는 값이 나올 수도 있다

			[0 ------ i] 구간 합 = pre
			[0 -- j]	 구간 합 = pre - k = x
				   [---] 구간 합 = k 가 될 수 있다

			그래서 원래는 0 ~ j ~ i 구간에서 순회를 돌면서 모든 경우를 조사했었는데
			그렇게 하지 않고 hashing 을 이용하면 O(1) 에 해결할 수 있다
		*/

		/*
			prefix sum 값이 k 는 안되는 데
			어느 구간 값을 빼면 k 가 될 수 있는, 값이 unordered map 에 있다면-

			pre - k 는 음수여도 되고 양수여도 된다
			그냥 그런 값이 존재하기만 하면 돼
		*/
		if (m.find(pre - k) != m.end()) {
			/*
				해당 구간 값을 빼면, pre -> k 가 된다

				k 를 만드는 구간이 [j+1, i]
				
				unordered map 에 저장해둔 인덱스 정보를 이용해서, 해당 구간을 뺐을 때의 구간을 구한다
				길이 갱신
			*/
			len = max(len, i - m[pre - k]);
		}
		else {
			/*
				unordered map 에 저장
					현재까지의 prefix sum 값과
					그 값을 만드는 데 필요한 인덱스를
					쌍으로 저장
					해당 prefix sum 을 구하는 데, 어느 인덱스까지 필요한지
					알아낼 수 있다
			*/
			m[pre] = i; //[] operator => 자동으로 만들고, 값 할당까지
		}

	}
	return len;

}
