/*
	Back Tracking => �����ϴ� ��� ����� ���� ���� => ���ϴ� ���� ã�´�
	Recursion => call stack �� �Լ� ȣ�� ������ ���̰� �ǰ� => ��� ���� ȣ���� ���ᰡ ��
	�׷��� �׿��� �Լ� ���õ��� ȣ��� �ݴ� ������ ������鼭
	=> ��� ����� ���� �����ϰ� �ȴ� = Back Tracking
	back tracking �� �ݵ�� funtion call ���Ŀ� �۾��ȴ�
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// ��� �κ������� ���ϴ� �Լ�
void findSubsets(char* input, char* output, int i, int j, vector<string>& strVec) {
	// base case, input ���� ��� ���ڸ� ���, ���̻� ������ ���ڰ� ����
	if (input[i] == '\0') {
		output[j] = '\0';
		/*if (j == 0) cout << "NULL";
		cout << output << endl;*/
		strVec.push_back(string(output)); // ���ݱ��� ������ output �� ���Ϳ� ����
		return;
	}

	// rec case
	// 2 ���� ����� ���� ���� sub problem ���� ������ �۰� ���� �� �ִ�
	// Include the ith letter
	output[j] = input[i];	// ���� input �� ���ڸ� �����ϴ� ���
	// �� �ڿ� ������ ��츦 ����
	// ���� ������ �ϴ� �� �ƴϰ�, ���� �������� ������ �پ��� ���̴�
	// �׷��� �־��� �ε��� ~ '\0' ���� ��� �� ������ �ִ� �Ŵ�
	findSubsets(input, output, i + 1, j + 1, strVec);

	// Exclude the ith letter
	// ���� input �� ���ڰ� ���Ե��� �ʴ� ���
	// Overwriting => output string �� ���� �Լ�ȣ�⿡�� ��������, �ٽ� �����Ѵ�
	findSubsets(input, output, i + 1, j, strVec);	  // �������� ���� ���� ���� => ����ض�
}
void mainFindSubsets() {
	/*
		string :: resize => string �� length ���� size ������ �����Ǿ��� ������
		�׷��� ���⼭ �տ� ���ڿ��� ��� �޵� ������ 100 ����� ���͹����� ���� �߰�
		�׷��� char array �� ����ؾ� �Ѵ�
		
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
		if (e1.length() == e2.length()) { // ���̰� ������ ���ڿ� �������
			return e1 < e2;
		}
		else return e1.length() < e2.length(); // �ƴϸ� ���̰� ª�� �� �������� ���� �Ѵ�
		});

	for (const string& x : strVec)
		//cout << x.length() << endl;
		cout << x << endl;
}


// �־��� ���ڿ��� ���� �� �ִ� ��� ������ ����ϴ� �Լ�
void permutation(string s, int i) { // i ��° ���� ~ ���ڿ� �������� �˻� �����̴�
// �˻� ������ ������ ������, �̷����̶� ���� ũ�⸦ ���̱� �����ϴ�
	//base case, ���̻� ������ ���� �� ����, ���ڰ� ������ ���ڴ�
	if (i == s.length()) {
		cout << s << endl;
		return;
	}

	//recursive case
	for (int j = i; j < s.length(); j++) {
		swap(s[i], s[j]);	   // ��� ���ڿ� ���ؼ� ���� �ѹ��� ������ ����
		permutation(s, i + 1); // �� �� ������ �������, ���� ũ�⸦ ���δ�
		swap(s[i], s[j]);	   // ���� �ٽ� ���󺹱� ��Ų��
	}
	return;
}


/*
	N-Queen ����, N ���� �� ü������, ���θ� ��Ƹ��� �ʴ� ��ġ�� �����ϵ��� �迭�϶�
	Back Tracking => Queen �� �ϳ��ϳ� ���ʴ�� �����鼭 ������ ������ �����ϴ� ��츦 ã�´�
*/
bool boardIsSafe(int board[][20], int n, int x, int y); // ���� ���� ���� ������ ��ġ�� ���̴� ���� Ȯ���ϴ� �Լ�
void solveNqueen(int n, int board[][20], int i) { // n �� �߿��� i ��° ���� ���� ��� => i ��° row �� ���´�
    //base case
    if (i == n) { // 0~n-1 row ���� ��� ���� n row �� ���� ��� => ���� �� �̻� ���� ���� ����
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++)
				cout << board[row][col] << " ";
			cout << endl;
		}
		cout << endl << endl;
        return;
    }

    //rec case, ������ �ɰ��� �Ѵ�
    for (int j = 0; j < n; j++) { // j = col �ε��� �ǹ�, i row �� j col �� ���� ���縦 �ϴ� ��
        if (boardIsSafe(board, n, i, j)) { // [i][j] �� ���� ���� �����ϴٸ�
            board[i][j] = 1;			   // ����
            solveNqueen(n, board, i + 1);  // �� ���� i+1 row ���� ���� ���� ������ �� �����Ѵ� => ������ �۰� �ɰ���
            //backtracking
            board[i][j] = 0;			   // ���� col ���� ���縦 �ϱ� ���� ���󺹱�
        }
    }
    return;
}
bool boardIsSafe(int board[][20], int n, int x, int y) {
	//checking the column
	for (int k = 0; k < x; k++)
	{
		if (board[k][y] == 1)
		{
			return false;
		}

	}
	//checking the left diagonal
	int i = x;
	int j = y;
	while (i >= 0 and j >= 0)
	{
		/* code */
		if (board[i][j] == 1)
		{
			/* code */
			return false;
		}
		i--, j--;
	}
	//checking right diagonal
	//your code is corrected here.
	//we have to initialize i & j again otherwise it will have -1 value for both i & j
	i = x;
	j = y;
	while (i >= 0 and j < n)
	{
		/* code */
		if (board[i][j] == 1)
		{
			/* code */
			return false;
		}
		i--, j++;
	}
	return true;
}




