/*
	�׷����� �׷��� Ȯ��
	�ݺ��������� �����ϴ� ������ ���ݾ� �ٿ������� ��� = Divide
	���� ������ ���ؼ� �۾� = Conquer
*/
#include<iostream>
#include<vector>
using namespace std;


/*
	�迭�� �Ѿ �ѹ��� ���� ���� �迭�� ���� ��, key �� ��ġ�� �ε�����?
	�� ������ ���, ��� ���� ������ Ǯ������ �ݺ��� ������
	���� �̹� �ܰ� �۾��� �����ϰ� => mid �� key ���� �����ϴ� �� Ȯ��
	���� ������ �پ���� �۾��� ���� => key �� ��ġ�� ������ ����ؼ� �˻� ������ ������
	�׷��� Divide and Conquer �̴�
*/
int rotated_search(vector<int> a,int key) {
	int n = a.size(); // ��ü ����

	// �˻� ���� �ε��� => ó������ �� ����
	int s = 0;
	int e = n - 1;

	while(s<=e){
		int mid = (s+e)/2; // �߰� �ε����� ���ؼ�

		if(a[mid]==key){	// �߰��� �ְų�
			return mid;
		}

		// �߰��� ���� �ּҰ��� �ְ��� ���� ��������, ��·�� �ѹ��� ���Ƽ� ���ĵǾ� �ִٴ� �� �̿�
		if(a[s]<=a[mid]){ // �ְ��� ������ �� ������ mid �� �ִ� ���
			//left
			if(key>=a[s] and key<=a[mid]){ // key �� ��ġ�� ������ �ٽ� ã�´�
				e = mid - 1;
			}
			else{
				s = mid + 1;
			}

		}
		else{ // �ּҰ� ���� ������ mid �� �ִ� ���
			//right
			if(key>=a[mid] and key<=a[e]){ // ���� key �� ��ġ�� ������ �ٽ� ã�´�
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