#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//k �� �����, ���� �� sub array �� ������
int longestSubarrayKSum(vector<int> arr, int k) {
	
	int n = arr.size(); //vector size

	//�ε��� i ������ prefix sum �� �����Ѵ�
	//{prefix sum, �װ� ����� �ε��� i} ����
	unordered_map<int, int> m{};
	
	
	int pre = 0; //prefix sum
	int len = 0; //k �� ����� �ִ� ����


	//�־��� vector ��ü ��Ҹ� �ѹ� �f�´�
	for (int i = 0; i < n; i++) {
		
		//prefix sum, �պκп��� ���� ��ġ ������ �� ��
		pre += arr[i];

		if (pre == k) { //���� prefix sum �� ���ϴ� ���� �ƴ�
			
			//�ִ� ���� �� ���� => ���� ���� �� or ���� �ε��� ���� ����?
			len = max(len, i + 1);
		}
		/*
			���� prefix sum �� ���ϴ� ���� �ƴ� ��� ��,

			prefix sum > k
			prefix sum < k

			prefix sum �� 0 ~ i ������ ���̴ϱ�, �߰��� j ~ i �� ���� ���ϸ�
			���ϴ� ���� ���� ���� �ִ�

			[0 ------ i] ���� �� = pre
			[0 -- j]	 ���� �� = pre - k = x
				   [---] ���� �� = k �� �� �� �ִ�

			�׷��� ������ 0 ~ j ~ i �������� ��ȸ�� ���鼭 ��� ��츦 �����߾��µ�
			�׷��� ���� �ʰ� hashing �� �̿��ϸ� O(1) �� �ذ��� �� �ִ�
		*/

		/*
			prefix sum ���� k �� �ȵǴ� ��
			��� ���� ���� ���� k �� �� �� �ִ�, ���� unordered map �� �ִٸ�-

			pre - k �� �������� �ǰ� ������� �ȴ�
			�׳� �׷� ���� �����ϱ⸸ �ϸ� ��
		*/
		if (m.find(pre - k) != m.end()) {
			/*
				�ش� ���� ���� ����, pre -> k �� �ȴ�

				k �� ����� ������ [j+1, i]
				
				unordered map �� �����ص� �ε��� ������ �̿��ؼ�, �ش� ������ ���� ���� ������ ���Ѵ�
				���� ����
			*/
			len = max(len, i - m[pre - k]);
		}
		else {
			/*
				unordered map �� ����
					��������� prefix sum ����
					�� ���� ����� �� �ʿ��� �ε�����
					������ ����
					�ش� prefix sum �� ���ϴ� ��, ��� �ε������� �ʿ�����
					�˾Ƴ� �� �ִ�
			*/
			m[pre] = i; //[] operator => �ڵ����� �����, �� �Ҵ����
		}

	}
	return len;

}
