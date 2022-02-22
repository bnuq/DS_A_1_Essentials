/*
Back Tracking => 존재하는 모든 솔루션을 구할 때, 가능한 답을 모두 찾을 때 사용
function call => call stack 에 함수 호출 스택이 쌓이게 되고 => 어느 순간 호출이 종료가 돼
그러면 쌓였던 함수 스택들이 후출된 반대 순서로 사라지면서 => main 함수로 돌아오게 되는데, 이때 돌아오는 과정 = back tracking
back tracking 은 반드시 funtion call 이후에 작업된다

앞선 함수 호출에서 썼던 건데, 안 쓴 것처럼 사용한다, 덮어쓰기

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
	output[j] = input[i];	// 현재 input 의 숫자를 포함할 때,
	findSubsets(input, output, i + 1, j + 1, strVec); // 그 뒤에 나오는 경우를 조사 => 출력하고

	// Exclude the ith letter
	// Overwriting => output string 이 이전 함수호출에서 사용됐지만, 다시 재사용한다
	findSubsets(input, output, i + 1, j, strVec);	  // 포함하지 않을 때를 조사 => 출력해라

}

void mainFindSubsets() {
	/*
	* string :: resize => string 의 length 값이 size 값으로 결정되어져 버린다
	* 그래서 여기서 앞에 문자열을 어떻게 받든 무조건 100 사이즈가 나와버리는 현상 발견
	* 그래서 char array 를 사용해야 한다
	string input{}; input.resize(100);
	string output{}; output.resize(100);
	getline(cin, input);
	*/
	char input[100];	cin >> input;
	char output[100];
	
	vector<string> strVec{};
	findSubsets(input, output, 0, 0, strVec);

	// 문제에서 원하는 대로 정렬해야 하는 경우가 있다 => custom comperator
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