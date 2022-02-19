#include <iostream>
#include <cstring>
using namespace std;

void cStyleString() {
	// 배열 초기화를 사용하거나, 큰 따옴표 이용 => 자동으로 배열로 바꿔준다
	char a[] = "abcdeghi";
	char aa[]{ 'a','b','h','\0' };

	// cin >> 입력 => 공백 없는 문자열 입력
	// '\n' 은 입력 안받고, 버퍼에 남아 있게 된다
	char b[100];
	cin >> b;
	// 문자열 길이 => <string> :: strlen
	cout << strlen(b) << endl; // number of visible characters
	cout << sizeof(b) << endl; // 배열 전체 크기

	char c[10];
	c[0] = cin.get(); // cin.get() => char 하나를 입력받는다 => 여기서는 버퍼에 남아있던 '\n' 입력 받음
	c[1] = '\0'; // cin.get() 은 넣기만 하므로, 문자열을 만들려면 널문자를 직접 넣어주어야 한다
	cout << c << endl;
	cout << strlen(c) << endl;

	// cin.getline() => 공백까지 입력받음, 최대 개수 지정 => cin.get() 과 다르게 argument 로 넘김
	// delimiter 를 만날때까지 입력 받는다, default = '\n'
	// delimiter 는 역시 버퍼에 그대로 남아 있지 않고 삭제된다
	char sentence[1000];
	cin.getline(sentence, 1000);
	cout << sentence << endl;
	char d; d = cin.get();

	char paragraph[1000];
	// delimiter = '.' 지정 => . 이 나오면 읽는 걸 멈춘다
	// 반대로 엔터를 눌러도 . 이 안나오면 계속 입력을 받는다
	cin.getline(paragraph, 1000, '.');
	cout << paragraph << endl;
	
	// . 이후에 입력을 위해 사용된 '\n' 을 제거
	d = cin.get();	cout << d << endl;
}

// Given a sentence, count the number of alphabets, digits & spaces in the sentence
void findChar() {
	//store and then count
	// read one by one and then count 
	char ch;
	ch = cin.get();

	//Count 
	int alpha = 0;
	int space = 0;
	int digit = 0;

	while (ch != '\n') {
		// 아스키 코드 값을 직접 쓰지 않고, 문자값을 직접 이용한다
		if (ch >= '0' and ch <= '9') {
			digit++;
		}
		else if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')) {
			alpha++;
		}
		// 공백은 한칸 공백 or 탭 공백
		else if (ch == ' ' or ch == '\t') {
			space++;
		}
		ch = cin.get();
	}
	cout << "Total Alphabets " << alpha << endl;
	cout << "Total Digits " << digit << endl;
	cout << "Total Space " << space << endl;
}

void cStyleStringOperation() {
	char a[1000] = "apple";
	char b[1000];

	//Calc Length 
	cout << strlen(a) << endl;

	//Strcpy 
	//strcpy(b,a); string copy b <- a
	strcpy_s(b, a);
	cout << b << endl;

	// strcmp = string compare a and b
	// 같을 때 0 리턴
	// a < b => 음수 리턴
	// a > b => 양수 리턴
	cout << strcmp(a, b) << endl;

	char web[100] = "www.";
	char domain[] = "codingminutes.com";

	// 두 문자열을 합치는 역할 strcat_s(a, b) == a + b
	// 그런데 합친 결과인 const char* 을 복사해서 리턴하는 게 아니고, a 배열에 저장한다
	// 그래서 a 배열 크기가 작으면 버퍼 오버플로우가 발생한다
	strcat_s(web, domain);
	cout << web << endl;
}

// c++ => std :: string class 사용한다
#include <string>
void stringClass() {
	string s0 = "Hello World"; // dynamic array
	string s1("Hello World");
	string s2{ "Hello World" };

	cout << s0 << endl << s1 << endl << s2 << endl;

	string s;

	// std::string 은 그냥 getline() 사용
	// cin stream 사용, string s 에 문자열 받는다, delimiter = 자동으로 제거해준다
	getline(cin, s, '.');
	cout << s << endl;
	cin.get(); // '\n' 제거

	string temp;
	// getline() default delimiter = '\n' => 따라서 그냥 사용하면 알아서 \n 전까지만 입력 받고
	// 또 \n 을 제거해주기까지 한다
	getline(cin, temp);

	// string length
	temp.length();

	// 숫자 -> string
	to_string(9);
}

int main() {
	stringClass();
}