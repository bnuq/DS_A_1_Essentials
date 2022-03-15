#include<iostream>
#include <vector>
using namespace std;


// ��ü ������ �����ϸ鼭 ��ġ��
void merge(vector<int> &array,int s,int e){ // s ~ e ���� ����
	int i = s;			// i ~ m ����
	int m = (s+e)/2;
	int j = m + 1;		// j ~ e ����

	vector<int> temp;
	while(i<=m and j<=e){ // �� ������ ���ؼ�
		if(array[i] < array[j]){
			temp.push_back(array[i]);
			i++;
		}
		else{
			temp.push_back(array[j]);
			j++;
		}
	}
	// ���� �� ���� �ֱ�
	//copy rem elements from first array
	while(i<=m){
		temp.push_back(array[i++]);
	}
	// or copy rem elements from second array
	while(j<=e){
		temp.push_back(array[j++]);
	}
	// �����ߴ� �� array �� �ֱ�
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
		return; // ��Ұ� �ϳ��� ���� => ���̻� ���� �� ����
	}
	//rec case
	int mid = (s+e)/2;		// �߰� �ε����� ��������
	// �ϳ��� ū ������ 2 ���� sub problems �� ������ => �ϴ� �����ϱ�, Divide
	mergesort(arr,s,mid);
	mergesort(arr,mid+1,e);
	// ������ ������ ����, �ذ��� �ϸ鼭 => �ٽ� big problem ���� ���ư���, Conquer
	// ���� �ܰ� ���� �ذ��� �����Ѵ�
	return merge(arr,s,e); // ���� ������ ��ġ�鼭 ����
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




