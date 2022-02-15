#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {


	vector<int> arr = { 10,11,2,3,4,6,7,8 };

	int key{ 2 };
	//cin>>key;

	/*
		find function <= algorithm �� ����
		iterator �� ����
		�� ã���� end() ����
	*/
	vector<int>::iterator it = find(arr.begin(), arr.end(), key);

	if (it != arr.end()) {
		cout << "Present at index " << it - arr.begin() << " , " << *it << endl;
	}
	else {
		cout << "Element not found" << endl;
	}


	// algorithm => search function => subsequence �� �����ϴ� �� ã�� �� ���δ�
	vector<int> bigVec{ 1,2,3,4,5,6,7 };
	vector<int> smallVec{ 4,5,6 };
	vector<int> otherVec{ 6,7,8 };

	vector<int>::iterator itr;
	itr = search(bigVec.begin(), bigVec.end(), smallVec.begin(), smallVec.end());
	if (itr != bigVec.end())
		cout << itr - bigVec.begin() << " , " << *itr << endl;


	itr = search(bigVec.begin(), bigVec.end(), otherVec.begin(), otherVec.end());
	if (itr != bigVec.end())
		cout << itr - bigVec.begin() << " , " << *itr << endl;
	else
		cout << "No element" << endl;


	// Predicate( comparator ) �߰� ���� => lambda expression = function object ���
	itr = search(bigVec.begin(), bigVec.end(), otherVec.begin(), otherVec.end(), [](const auto& e1, const auto& e2) {
		// �׳� ������ �´ٰ� ��
		return true;
		});
	if (itr != bigVec.end())
		cout << itr - bigVec.begin() << " , " << *itr << endl;
	else
		cout << "No element" << endl;

	
	// �̸� ���ĵ� container �� ���ؼ� ����Ž���� �����Ѵ�
	// return boolean
	vector<int> aVec{ 2,3,1,5,4,8,1,9,4 };
	
	// ������ ���� �Ǿ� �־�� �Ѵ�
	sort(aVec.begin(), aVec.end());
	cout << binary_search(aVec.begin(), aVec.end(), 3) << endl;


	/*
	lower_bound
		returns an iterator to the first element not less than the given value	
	upper_bound
		returns an iterator to the first element greater than a certain value
	*/
	itr = lower_bound(aVec.begin(), aVec.end(), 7);
	cout << itr - aVec.begin() << " , " << *itr << endl;

	itr = upper_bound(aVec.begin(), aVec.end(), 8);
	cout << itr - aVec.begin() << " , " << *itr << endl;

	return 0;
}