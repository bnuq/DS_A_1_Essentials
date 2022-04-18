/*
* std::vector
* 
* Data Member
	* array
	* size => ���� ����ϴ� ���� => ���� ����
	* capacity => ���� �޸𸮸� �Ҵ��� ���� => ���� �Ұ���
* 
* Member Function
	* push_back(d) => �ڿ� ����, capacity �� �����ϸ� ������ 2�踦 ���Ҵ��ؼ� ���� ���͸� �����
	* pop_back() => ���� �� ����
	
	* front()
	* back()
	 
	* empty() => vector �� ����� ��, �ƴ���
	* at(i)
	* size()
	* capacity()

	* emplace_back(d) => �ڿ� �� �߰�, �����ؼ� ���� �ʰ� ���Ϳ� ������ ����鼭 �ٷ� �ʱ�ȭ�Ѵ�
	* emplace(itr, d) => itr �տ� ���� �߰����ش�, list ó�� ����� �����ϴ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<string, int> f1, pair<string, int> f2) {
	
	// comparator �� ������ ��, ���ʿ� �ִ� ���� ������ ���ʿ� ���ĵȴٰ� �����ϸ� �ȴ�
	// ��, second ���� ū �� => ���� ��, ������ ���ĵ� ���̴�
	return f1.second > f2.second;
}

void vectorDemo(int row, int col) {
	// Fill Constructor, �̿��ؼ� 2���� ���� �����
	vector<vector<int>> vec1(row, vector<int>(col, 10));
	//vector<vector<int>> vec2{ row, vector<int>{col, 100} };

	vector<pair<string, int> > fruits = {
		{"apple",10},
		{"mango",100},
		{"guava",20},
		{"papaya",40},
		{"orange",60},
		{"banana",120},
	};

	// vector => iterator ���� => sort �� ������ �� �ִ�
	// function pointer, function object, lambda expression ��� ��� ����
	sort(fruits.begin(), fruits.end(), compare);

	// emplace ��� => ��ü�� ���� �ʰ� �� ��ü�� ����� �� �ʿ��� argument �� �־��ָ� �ȴ�
	fruits.emplace_back("string", 99);
	fruits.emplace(fruits.end(), "keroro", 90);
	// emplace �� �߰��� ���Ե� �����ϴ� => array �ε� �߰� ������ �����ϴ�!
	fruits.emplace(fruits.begin() + 3, "�տ� 3���� �ִ�", 999);

	for (auto x : fruits)
		cout << x.first << " , " << x.second << endl;
}

void vectorSearch() {

	vector<int> arr = { 10,11,2,3,4,6,7,8 };
	int key{ 2 };
	
	/*
	algorithm :: find function => �־��� key �� ã�´�
	key �� �����ϴ� iterator �� ����
	�� ã���� end() ����
	*/
	vector<int>::iterator it = find(arr.begin(), arr.end(), key);
	if (it != arr.end()) {
		cout << "Present at index " << it - arr.begin() << " , " << *it << endl;
	}
	else {
		cout << "Element not found" << endl;
	}


	/*
	algorithm :: search function => subsequence �� �����ϴ� �� ã�� �� ���δ�
	������ subsequence �� �����Ѵٸ�, ���� ��ġ iterator return
	*/
	vector<int> bigVec{ 1,2,3,4,5,6,7 };
	vector<int> smallVec{ 4,5,6 };
	vector<int> otherVec{ 6,7,8 };

	vector<int>::iterator itr;
	// ã������ sequence ������ ��� sequence ������ ����
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


	
	vector<int> aVec{ 2,3,1,5,4,8,1,9,4 };

	/*
	�̹� ���ĵ� vector ��� => ����Ž������ �� ���� �˻��� �� �� �ִ�
	algorithm :: binary_search function �̿�
	*/
	sort(aVec.begin(), aVec.end());
	cout << binary_search(aVec.begin(), aVec.end(), 3) << endl;


	/*
	lower_bound
		returns an iterator to the first element not less than the given value
		given value �� ���ų� ū �� ��, ù��°�� ���� ���� ��ġ�� ����
	upper_bound
		returns an iterator to the first element greater than a certain value
		given value ���� ������ ū �� ��, ���� ���� ���� ���� ��ġ ����
	*/
	vector<int> bVec{ 2,3,1,5,4,8,1,9,4 };
	itr = lower_bound(bVec.begin(), bVec.end(), 8);
	cout << itr - bVec.begin() << " , " << *itr << endl;

	itr = upper_bound(bVec.begin(), bVec.end(), 8);
	cout << itr - bVec.begin() << " , " << *itr << endl;
}



int main() {
	vectorSearch();
}