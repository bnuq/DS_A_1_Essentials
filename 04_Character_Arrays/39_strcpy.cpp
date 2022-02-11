#include<iostream>
using namespace std;
	
/*
	For C - Style String
*/
/*
	strcpy_s �ϰ� strcat_s �� �޴� ���ڰ� �پ�����, �� ����������
	C++20 �����鼭 �� ����ȭ �Ƴ�??
*/
int main(){

	char a[1000] = "apple";
	char b[1000];

	//Calc Length 
	cout<< strlen(a) <<endl;

	//Strcpy 
	//strcpy(b,a); // string copy a to b
	strcpy_s(b, a);
	cout << b <<endl;



	//Compare : string �� ������ �ƴ���
	// ���� �� 0 ����
	// a < b => ���� ����
	// a > b => ��� ����
	cout << strcmp(a,b) <<endl;
	//strcmp
	
	char web[100] = "www.";
	char domain[] = "codingminutes.com";

	
	// �� ���ڿ��� ��ġ�� ���� strcat_s(a, b) == a + b
	// �׷��� ��ģ ����� const char* �� �����ؼ� �����ϴ� �� �ƴϰ�, a �迭�� �����Ѵ�
	// �׷��� a �迭 ũ�Ⱑ ������ ���� �����÷ο찡 �߻��Ѵ�
	// ���� �����ϴ� �Լ��� �ƴϴ�
	strcat_s(web, domain);
	strcpy_s(b, web);
	cout << b << endl;


	cout << strcmp(b,a) <<endl;



	return 0;
}