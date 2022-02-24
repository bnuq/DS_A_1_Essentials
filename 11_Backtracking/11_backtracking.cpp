/*
	Back Tracking => 존재하는 모든 경우의 수를 조사 => 원하는 답을 찾는다
	Recursion => call stack 에 함수 호출 스택이 쌓이게 되고 => 어느 순간 호출이 종료가 돼
	그러면 쌓였던 함수 스택들이 호출된 반대 순서로 사라지면서
	=> 모든 경우의 수를 조사하게 된다 = Back Tracking
	back tracking 은 반드시 funtion call 이후에 작업된다
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// 모든 부분집합을 구하는 함수
void findSubsets(char* input, char* output, int i, int j, vector<string>& strVec) {
	// base case, input 에서 모든 문자를 사용, 더이상 조사할 문자가 없다
	if (input[i] == '\0') {
		output[j] = '\0';
		/*if (j == 0) cout << "NULL";
		cout << output << endl;*/
		strVec.push_back(string(output)); // 지금까지 조사한 output 을 벡터에 저장
		return;
	}

	// rec case
	// 2 가지 경우의 수에 따라 sub problem 으로 문제를 작게 만들 수 있다
	// Include the ith letter
	output[j] = input[i];	// 현재 input 의 숫자를 포함하는 경우
	// 그 뒤에 나오는 경우를 조사
	// 딱히 뭔가를 하는 게 아니고, 같은 문제에서 구간만 줄어드는 것이다
	// 그래서 주어진 인덱스 ~ '\0' 까지 라는 게 정해져 있는 거다
	findSubsets(input, output, i + 1, j + 1, strVec);

	// Exclude the ith letter
	// 현재 input 의 숫자가 포함되지 않는 경우
	// Overwriting => output string 이 이전 함수호출에서 사용됐지만, 다시 재사용한다
	findSubsets(input, output, i + 1, j, strVec);	  // 포함하지 않을 때를 조사 => 출력해라
}
void mainFindSubsets() {
	/*
		string :: resize => string 의 length 값이 size 값으로 결정되어져 버린다
		그래서 여기서 앞에 문자열을 어떻게 받든 무조건 100 사이즈가 나와버리는 현상 발견
		그래서 char array 를 사용해야 한다
		
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
		if (e1.length() == e2.length()) { // 길이가 같으면 문자열 순서대로
			return e1 < e2;
		}
		else return e1.length() < e2.length(); // 아니면 길이가 짧은 게 왼쪽으로 오게 한다
		});

	for (const string& x : strVec)
		//cout << x.length() << endl;
		cout << x << endl;
}


// 주어진 문자열로 만들 수 있는 모든 순열을 출력하는 함수
void permutation(string s, int i) { // i 번째 부터 ~ 문자열 끝까지가 검색 구간이다
// 검색 구간이 어디부터 끝까지, 이런식이라서 문제 크기를 줄이기 수월하다
	//base case, 더이상 구간을 줄일 수 없다, 문자가 마지막 문자다
	if (i == s.length()) {
		cout << s << endl;
		return;
	}

	//recursive case
	for (int j = i; j < s.length(); j++) {
		swap(s[i], s[j]);	   // 모든 문자에 대해서 각각 한번씩 앞으로 빼고
		permutation(s, i + 1); // 그 뒤 구간을 대상으로, 문제 크기를 줄인다
		swap(s[i], s[j]);	   // 이후 다시 원상복귀 시킨다
	}
	return;
}


/*
	N-Queen 문제, N 개의 퀸 체스말이, 서로를 잡아먹지 않는 위치에 존재하도록 배열하라
	Back Tracking => Queen 을 하나하나 차례대로 놓으면서 문제의 조건을 충족하는 경우를 찾는다
*/
bool boardIsSafe(int board[][20], int n, int x, int y); // 보드 위의 말이 적절한 위치에 놓이는 건지 확인하는 함수
void solveNqueen(int n, int board[][20], int i) { // n 개 중에서 i 번째 퀸을 놓는 경우 => i 번째 row 에 놓는다
    //base case
    if (i == n) { // 0~n-1 row 까지 모두 놓고 n row 에 놓는 경우 => 이제 더 이상 놓을 퀸이 없다
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++)
				cout << board[row][col] << " ";
			cout << endl;
		}
		cout << endl << endl;
        return;
    }

    //rec case, 문제를 쪼개야 한다
    for (int j = 0; j < n; j++) { // j = col 인덱스 의미, i row 의 j col 에 대한 조사를 하는 것
        if (boardIsSafe(board, n, i, j)) { // [i][j] 에 놓는 것이 가능하다면
            board[i][j] = 1;			   // 놓고
            solveNqueen(n, board, i + 1);  // 그 다음 i+1 row 에서 놓는 것이 가능한 지 조사한다 => 문제를 작게 쪼갰다
            //backtracking
            board[i][j] = 0;			   // 다음 col 에서 조사를 하기 위해 원상복귀
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




