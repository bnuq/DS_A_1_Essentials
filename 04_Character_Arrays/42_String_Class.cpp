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
	
	// cin 사용, string s 에 문자 받아, . 나올때까지 받는다
	// . 은 자동으로 삭제
	getline(cin, s, '.');
	// \n 제거
	cin.get();
	

	for (char ch : s)
		cout << ch << " , ";
	cout << endl;



	// vector<string>
	int n{ 5 };
	vector<string> sarr;
	string temp;

	while (n--) {
		// 확실히 \n 까지 입력받지만, \n 은 제거하고 그 앞까지만 입력받는다
		getline(cin, temp);
		sarr.push_back(temp);
	}

	for (string ss : sarr)
		cout << ss << " ";
}