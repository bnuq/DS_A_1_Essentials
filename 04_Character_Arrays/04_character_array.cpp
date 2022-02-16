#include <iostream>
#include <cstring>
using namespace std;

void cStyleString() {
	// �迭 �ʱ�ȭ�� ����ϰų�, ū ����ǥ �̿� => �ڵ����� �迭�� �ٲ��ش�
	char a[] = "abcdeghi";
	char aa[]{ 'a','b','h','\0' };

	// cin >> �Է� => ���� ���� ���ڿ� �Է�
	// '\n' �� �Է� �ȹް�, ���ۿ� ���� �ְ� �ȴ�
	char b[100];
	cin >> b;
	// ���ڿ� ���� => <string> :: strlen
	cout << strlen(b) << endl; // number of visible characters
	cout << sizeof(b) << endl; // �迭 ��ü ũ��

	char c[10];
	c[0] = cin.get(); // cin.get() => char �ϳ��� �Է¹޴´� => ���⼭�� ���ۿ� �����ִ� '\n' �Է� ����
	c[1] = '\0'; // cin.get() �� �ֱ⸸ �ϹǷ�, ���ڿ��� ������� �ι��ڸ� ���� �־��־�� �Ѵ�
	cout << c << endl;
	cout << strlen(c) << endl;

	// cin.getline() => ������� �Է¹���, �ִ� ���� ���� => cin.get() �� �ٸ��� argument �� �ѱ�
	// delimiter �� ���������� �Է� �޴´�, default = '\n'
	// delimiter �� ���� ���ۿ� �״�� ���� ���� �ʰ� �����ȴ�
	char sentence[1000];
	cin.getline(sentence, 1000);
	cout << sentence << endl;
	char d; d = cin.get();

	char paragraph[1000];
	// delimiter = '.' ���� => . �� ������ �д� �� �����
	// �ݴ�� ���͸� ������ . �� �ȳ����� ��� �Է��� �޴´�
	cin.getline(paragraph, 1000, '.');
	cout << paragraph << endl;
	
	// . ���Ŀ� �Է��� ���� ���� '\n' �� ����
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
		// �ƽ�Ű �ڵ� ���� ���� ���� �ʰ�, ���ڰ��� ���� �̿��Ѵ�
		if (ch >= '0' and ch <= '9') {
			digit++;
		}
		else if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')) {
			alpha++;
		}
		// ������ ��ĭ ���� or �� ����
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
	// ���� �� 0 ����
	// a < b => ���� ����
	// a > b => ��� ����
	cout << strcmp(a, b) << endl;

	char web[100] = "www.";
	char domain[] = "codingminutes.com";

	// �� ���ڿ��� ��ġ�� ���� strcat_s(a, b) == a + b
	// �׷��� ��ģ ����� const char* �� �����ؼ� �����ϴ� �� �ƴϰ�, a �迭�� �����Ѵ�
	// �׷��� a �迭 ũ�Ⱑ ������ ���� �����÷ο찡 �߻��Ѵ�
	strcat_s(web, domain);
	cout << web << endl;
}

// c++ => std :: string class ����Ѵ�
#include <string>
void stringClass() {
	string s0 = "Hello World"; // dynamic array
	string s1("Hello World");
	string s2{ "Hello World" };

	cout << s0 << endl << s1 << endl << s2 << endl;

	string s;

	// std::string �� �׳� getline() ���
	// cin stream ���, string s �� ���ڿ� �޴´�, delimiter = �ڵ����� �������ش�
	getline(cin, s, '.');
	cout << s << endl;
	cin.get(); // '\n' ����

	string temp;
	// getline() default delimiter = '\n' => ���� �׳� ����ϸ� �˾Ƽ� \n �������� �Է� �ް�
	// �� \n �� �������ֱ���� �Ѵ�
	getline(cin, temp);

	// string length
	temp.length();

	// ���� -> string
	to_string(9);
}

int main() {
	stringClass();
}