#include<iostream>
using namespace std;


int main(){

	char sentence[1000];

	// char �ϳ��� �Է� �޴´�
	char temp = cin.get();

	int len = 0;

	//could have checked our len doesn't exceed the sentence array, additional check
	// char �� �ϳ��� �Է¹޴ٺ���, ���� �Է��� '\n' �� �Է¹޴´�
	// �� 'h''e''l''l''o''\n' �� �Է��� �Ǵ� �ǰ�
	// �ι��ڴ� �Է� �ȵȴ� => cin >> �� �˾Ƽ� ȥ�� �� ó���ϴ���...
	while(temp!='\0'){
		sentence[len++] = temp;
		//sentence[len++] = '\n';

		temp = cin.get();
	}

	// �ѱ��ھ� �־����ϱ�, �ι��ڴ� ���� �־��ش�
	sentence[len] = '\0';

	cout<<"Length "<<len <<endl;

	cout << sentence <<endl;
}