#include<iostream>
using namespace std;



int main(){

	char sentence[1000];

	// �ִ� �Է¹��� �� �ִ� �޸𸮸� ���� ���´�
	cin.getline(sentence,1000);

	cout << sentence <<endl;

	cout << strlen( sentence ) << endl;
	cout << sizeof(sentence) << endl;

}