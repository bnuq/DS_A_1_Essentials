#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s0 = "Hello World"; // dynamic array
	string s1("Hello World");
	string s2{ "Hello World" };

	cout << s0 << endl
		<< s1 << endl
		<< s2 << endl;


	string s;
	
	// cin ���, string s �� ���� �޾�, . ���ö����� �޴´�
	// . �� �ڵ����� ����
	getline(cin, s, '.');
	// \n ����
	cin.get();
	

	for (char ch : s)
		cout << ch << " , ";
	cout << endl;



	// vector<string>
	int n{ 5 };
	vector<string> sarr;
	string temp;

	while (n--) {
		// Ȯ���� \n ���� �Է¹�����, \n �� �����ϰ� �� �ձ����� �Է¹޴´�
		getline(cin, temp);
		sarr.push_back(temp);
	}

	for (string ss : sarr)
		cout << ss << " ";
}