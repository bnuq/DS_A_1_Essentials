#include<iostream>
using namespace std;



int main(){

	char sentence[1000];

	// �ִ� �Է¹��� �� �ִ� �޸𸮸� ���� ���´�
	// �迭 �ּ�, ���� ũ��
	cin.getline(sentence,1000);

	cout << sentence <<endl;

	cout << strlen( sentence ) << endl;
	cout << sizeof(sentence) << endl;

}