/*
Back Tracking => �����ϴ� ��� �ַ���� ���� ��, ������ ���� ��� ã�� �� ���
function call => call stack �� �Լ� ȣ�� ������ ���̰� �ǰ� => ��� ���� ȣ���� ���ᰡ ��
�׷��� �׿��� �Լ� ���õ��� ����� �ݴ� ������ ������鼭 => main �Լ��� ���ƿ��� �Ǵµ�, �̶� ���ƿ��� ���� = back tracking
back tracking �� �ݵ�� funtion call ���Ŀ� �۾��ȴ�

�ռ� �Լ� ȣ�⿡�� ��� �ǵ�, �� �� ��ó�� ����Ѵ�, �����

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void findSubsets(char* input, char* output, int i, int j, vector<string>& strVec) { // 111
	// base case
	if (input[i] == '\0') {
		output[j] = '\0';
		/*if (j == 0) cout << "NULL";
		cout << output << endl;*/
		strVec.push_back(string(output));
		return;
	}

	// rec case
	// Include the ith letter
	output[j] = input[i];	// ���� input �� ���ڸ� ������ ��,
	findSubsets(input, output, i + 1, j + 1, strVec); // �� �ڿ� ������ ��츦 ���� => ����ϰ�

	// Exclude the ith letter
	// Overwriting => output string �� ���� �Լ�ȣ�⿡�� ��������, �ٽ� �����Ѵ�
	findSubsets(input, output, i + 1, j, strVec);	  // �������� ���� ���� ���� => ����ض�

}

void mainFindSubsets() {
	/*
	* string :: resize => string �� length ���� size ������ �����Ǿ��� ������
	* �׷��� ���⼭ �տ� ���ڿ��� ��� �޵� ������ 100 ����� ���͹����� ���� �߰�
	* �׷��� char array �� ����ؾ� �Ѵ�
	string input{}; input.resize(100);
	string output{}; output.resize(100);
	getline(cin, input);
	*/
	char input[100];	cin >> input;
	char output[100];
	
	vector<string> strVec{};
	findSubsets(input, output, 0, 0, strVec);

	// �������� ���ϴ� ��� �����ؾ� �ϴ� ��찡 �ִ� => custom comperator
	sort(strVec.begin(), strVec.end(), [](const string& e1, const string& e2) {
		if (e1.length() == e2.length()) {
			return e1 < e2;
		}
		else return e1.length() < e2.length();
		});

	for (const string& x : strVec)
		//cout << x.length() << endl;
		cout << x << endl;
}




/*
Restore the original array while going back = Back Tracking
*/
// 112
void my_Permutation(string input, string output, int startInd, vector<string>& vec) {
	

	if(startInd > input.size()) {
		cout << input.size() << endl;
		vec.push_back(output);
		return;
	}

	for (int i = startInd; i < input.size(); i++) {
		swap(input[startInd], input[i]);
		string temp = output + input[startInd];
		my_Permutation(input, temp, startInd + 1, vec);
	}

}

void permutation(string s, int i) {
	//base case
	if (i == s.length()) {
		cout << s << endl;
		return;
	}


	//recursive case
	for (int j = i; j < s.length(); j++) {
		swap(s[i], s[j]);
		permutation(s, i + 1);
		swap(s[i], s[j]);
	}
	return;
}

//
//#include <array>
//int main() {
//	/*array<char, 100> name{ "TEST" };
//	string strName{ name.data()};
//
//	cout << name.size() << endl;
//	cout << strName.size() << endl;*/
//	string input{ "ABC" };
//	string output{};
//	vector<string> vec{};
//	my_Permutation(input, output, 0, vec);
//
//	for (auto x : vec) {
//		cout << x << endl;
//	}
//	cout << vec.size() << endl;
//}

void findPermutations(std::string& s, size_t i = 0) {
	// base case
	if (i == s.length() - 1) {
		std::cout << s << '\n';
		return;
	}

	for (size_t j{ i }; j < s.length(); ++j) {
		std::swap(s[i], s[j]);

		// recursive call
		findPermutations(s, i + 1);

		// backtracking step (restore original string)
		std::swap(s[i], s[j]);
	}
}

int main() {
	std::string s{ "abcdef" };
	findPermutations(s);
}