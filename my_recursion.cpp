#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

/*
	결국 핵심은, 하나의 큰 문제를 사이즈만 다른 sub problem 으로 어떻게 나눌 것이냐?
	큰 문제를 작은 문제로 나누는 과정 == 작은 문제를 더 작은 문제로 나누는 과정 ==> 더이상 나눌 수 없을 때는 언제인가?
	그래서 큰 문제를 작은 문제로 나누는 과정을 명확하게 판단해야 한다
*/
void my_AllSubsets(vector<string>& vec, array<char, 100>& input, array<char, 100>& output, int inputInd, int outputInd) {
	// base case
	if (input[inputInd] == '\0') {
		output[outputInd] = '\0';
		vec.push_back(string(output.data()));
		return;
	}

	/*
		이 문제에서 큰 문제를 작은 문제로 나누는 방법 = inputInd 에 해당하는 문자를 포함하고 sub problem 을 풀지, 포함하지 않고 sub problem 을 풀지
		new input index 이하의 문자들을 이용해서, new output index 이하의 영역에 문자들을 채운다
	*/

	// inputInd 가 포함되는 경우
	output[outputInd] = input[inputInd];
	// sub problem 을 조사한다
	my_AllSubsets(vec, input, output, inputInd + 1, outputInd + 1);

	// inputInd 가 포함되지 않는 경우의 sub problem 도 조사한다
	output[outputInd] = ' ';	// 앞에서 input[inputInd] 넣었던 것을 초기화 한다는 뜻, 근데 어차피 다음 과정에서 덮어써서 없어도 무관하다
	my_AllSubsets(vec, input, output, inputInd + 1, outputInd);
}


void subsetMain() {
	array<char, 100> input{ "poiuy" };
	array<char, 100> output{};
	vector<string> str{};

	my_AllSubsets(str, input, output, 0, 0);
	sort(str.begin(), str.end(), [](const string& e1, const string& e2) {
		if (e1.length() != e2.length()) return e1.length() < e2.length();
		else return e1 < e2;
		});

	for (const auto& x : str)
		cout << x << endl;
}




/*
주어진 문자열로 만들 수 있는 순열의 모든 경우를 구하는 함수
어떤 큰 문자열에서 순열을 구해야 하는 데 => 작은 sub problem 으로 나누려면 어떻게 해야할까
inputInd 가 input 가장 앞에 있는 인덱스일 때, 여기서부터 문자열 끝까지 각 문자가 output 의 outputInd 에 들어가는 경우
뒤에 남은 문자열로 만드는 순열을 구하는 걸로 바꿀 수 있다
그렇게 나누다가, 문자가 하나만 남았을 경우 => 끝

Permutation 을 구하는 문제에서, output 을 따로 만들려고 하면
output 에 들어온 문자 종류, 문자 개수에 따라서 그 다음 sub problem 을 만들 때 필요한 정보가 점점 많아지게 된다 => 중복을 하면 안되니까
따라서 무조건 swap 을 해서 연속된 검색 범위가 줄어들게 해야 한다
*/
void my_Permutation(vector<string>& vec, array<char, 100>& input, array<char, 100>& output, int inputInd, int outputInd) {

	if (input[inputInd] == '\0') {
		output[outputInd] = '\0';
		vec.push_back(string(output.data()));
		return;
	}


	for (int i = inputInd; i < 4; i++) {
		swap(input[i], input[inputInd]);

		output[outputInd] = input[inputInd];
		// sub problem 을 만들었다
		my_Permutation(vec, input, output, inputInd + 1, outputInd + 1);

		// 넣었던 output 을 다시 정리해준다 => 근데 어차피 덮어쓰니까 없어도 된다
		output[outputInd] = ' ';

		swap(input[i], input[inputInd]); // input 에서 swap 했던 것도 정리
	}
}
/*
	이제 보니까, 무조건 swap 을 해야하는 상황 + 원본 input 을 그대로 이용한다는 점
	=> output 에 따로 담지 않고, input 내에서 직접 변경해서 그걸 결과물에 담는 게 훨씬 자연스럽긴 하네

	sub problem, 더 작은 문제로 만들어야 한다
*/


void test2(vector<string>& vec, array<char, 100>& input, array<char, 100>& output, int outputInd) {

	if (outputInd == 3) {
		output[outputInd] = '\0';
		vec.push_back(string(output.data()));
		return;
	}


	for (int i = 0; i < 3; i++) {
		output[outputInd] = input[i];
		// sub problem 을 만들었다
		test2(vec, input, output, outputInd + 1);
	}
}


int main() {
	/*array<char, 100> input{ "3456" };
	array<char, 100> output{};
	vector<string> str{};

	my_Permutation(str, input, output, 0, 0);

	for (auto x : str)
		cout << x << endl;*/


	array<char, 100> input{ "123" };
	array<char, 100> output{};
	vector<string> str{};

	test2(str, input, output, 0);
	for (auto x : str)
		cout << x << endl;
}