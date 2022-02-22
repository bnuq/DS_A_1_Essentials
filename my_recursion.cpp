#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

/*
	�ᱹ �ٽ���, �ϳ��� ū ������ ����� �ٸ� sub problem ���� ��� ���� ���̳�?
	ū ������ ���� ������ ������ ���� == ���� ������ �� ���� ������ ������ ���� ==> ���̻� ���� �� ���� ���� �����ΰ�?
	�׷��� ū ������ ���� ������ ������ ������ ��Ȯ�ϰ� �Ǵ��ؾ� �Ѵ�
*/
void my_AllSubsets(vector<string>& vec, array<char, 100>& input, array<char, 100>& output, int inputInd, int outputInd) {
	// base case
	if (input[inputInd] == '\0') {
		output[outputInd] = '\0';
		vec.push_back(string(output.data()));
		return;
	}

	/*
		�� �������� ū ������ ���� ������ ������ ��� = inputInd �� �ش��ϴ� ���ڸ� �����ϰ� sub problem �� Ǯ��, �������� �ʰ� sub problem �� Ǯ��
		new input index ������ ���ڵ��� �̿��ؼ�, new output index ������ ������ ���ڵ��� ä���
	*/

	// inputInd �� ���ԵǴ� ���
	output[outputInd] = input[inputInd];
	// sub problem �� �����Ѵ�
	my_AllSubsets(vec, input, output, inputInd + 1, outputInd + 1);

	// inputInd �� ���Ե��� �ʴ� ����� sub problem �� �����Ѵ�
	output[outputInd] = ' ';	// �տ��� input[inputInd] �־��� ���� �ʱ�ȭ �Ѵٴ� ��, �ٵ� ������ ���� �������� ����Ἥ ��� �����ϴ�
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
�־��� ���ڿ��� ���� �� �ִ� ������ ��� ��츦 ���ϴ� �Լ�
� ū ���ڿ����� ������ ���ؾ� �ϴ� �� => ���� sub problem ���� �������� ��� �ؾ��ұ�
inputInd �� input ���� �տ� �ִ� �ε����� ��, ���⼭���� ���ڿ� ������ �� ���ڰ� output �� outputInd �� ���� ���
�ڿ� ���� ���ڿ��� ����� ������ ���ϴ� �ɷ� �ٲ� �� �ִ�
�׷��� �����ٰ�, ���ڰ� �ϳ��� ������ ��� => ��

Permutation �� ���ϴ� ��������, output �� ���� ������� �ϸ�
output �� ���� ���� ����, ���� ������ ���� �� ���� sub problem �� ���� �� �ʿ��� ������ ���� �������� �ȴ� => �ߺ��� �ϸ� �ȵǴϱ�
���� ������ swap �� �ؼ� ���ӵ� �˻� ������ �پ��� �ؾ� �Ѵ�
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
		// sub problem �� �������
		my_Permutation(vec, input, output, inputInd + 1, outputInd + 1);

		// �־��� output �� �ٽ� �������ش� => �ٵ� ������ ����ϱ� ��� �ȴ�
		output[outputInd] = ' ';

		swap(input[i], input[inputInd]); // input ���� swap �ߴ� �͵� ����
	}
}
/*
	���� ���ϱ�, ������ swap �� �ؾ��ϴ� ��Ȳ + ���� input �� �״�� �̿��Ѵٴ� ��
	=> output �� ���� ���� �ʰ�, input ������ ���� �����ؼ� �װ� ������� ��� �� �ξ� �ڿ������� �ϳ�

	sub problem, �� ���� ������ ������ �Ѵ�
*/


void test2(vector<string>& vec, array<char, 100>& input, array<char, 100>& output, int outputInd) {

	if (outputInd == 3) {
		output[outputInd] = '\0';
		vec.push_back(string(output.data()));
		return;
	}


	for (int i = 0; i < 3; i++) {
		output[outputInd] = input[i];
		// sub problem �� �������
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