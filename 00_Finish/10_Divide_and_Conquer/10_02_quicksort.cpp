/*
	�׻� ���� �������� �ִ� ���� pivot ���� �����Ѵ�
	pivot ���� �������� ���� ����� ū ������ ������ => Divide, Sub Problem ���� ������
	������ ������ �����Ѵ� => Conquer, ���� �ܰ� �ذ�
*/
#include<iostream>
#include <vector>
using namespace std;


int partition(vector<int> &a,int s,int e){ // ���� s~e �� �����Ѵ�
	int pivot = a[e];	// ���� �ִ� ���� pivot ����
	int i = s - 1;		// pivot ���� ū ���� ���ʿ� ��ġ�ϴ� �ε���
	/*
		pivot ���� ���� ��, ū ���� ������ �۾��� �ϴµ� �־�, � �ٸ� �ڷᱸ���� �̿����� �ʾҴ�
		��ġ �ε����� swap �� �̿��ؼ� �����س´�
	*/
	for(int j=s;j<e;j++){
		if(a[j] < pivot){
			i++;
			swap(a[i],a[j]);
		}
	}	
	swap(a[i+1],a[e]); // �������� pivot �� ����� ��ġ�ϵ��� �Ѵ�
	return i + 1;	   // pivot �� �ε��� ����	
}


void quicksort(vector<int> &a, int s,int e){
	//Base Case
	if(s>=e){
		return; // ���̻� ���� �� ���� ��
	}
	//Rec Case
	// ���� �ܰ迡�� �۾��� ���� ���� => pivot �� �߽����� ������ �۾��� ���� �ϰ�
	// �̰� ���������� ������ �ϴ� �����ΰŰ�
	int p = partition(a,s,e);
	
	// �� ���� sub problems �� ������ �۾��� �����Ѵ�
	// �̰� ��ǻ� �׳� ���� ���̱⸸ �ϴ� ����
	quicksort(a,s,p-1);
	quicksort(a,p+1,e);
}


int main(){
    vector<int> arr{10,5,2,0,7,6,4};
    cout<< arr.size() <<endl;
    int n = arr.size();

    quicksort(arr,0,n-1);

    for(int x :arr){
    	cout << x << " ";
    }

    return 0;
}
