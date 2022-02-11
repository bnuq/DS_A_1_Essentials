#include<iostream>
using namespace std;


int main(){

	char sentence[1000];

	// char 하나씩 입력 받는다
	char temp = cin.get();

	int len = 0;

	//could have checked our len doesn't exceed the sentence array, additional check
	// char 를 하나씩 입력받다보니, 내가 입력한 '\n' 도 입력받는다
	// 즉 'h''e''l''l''o''\n' 가 입력이 되는 건가
	// 널문자는 입력 안된다 => cin >> 은 알아서 혼자 잘 처리하던데...
	while(temp!='\0'){
		sentence[len++] = temp;
		//sentence[len++] = '\n';

		temp = cin.get();
	}

	// 한글자씩 넣었으니까, 널문자는 내가 넣어준다
	sentence[len] = '\0';

	cout<<"Length "<<len <<endl;

	cout << sentence <<endl;
}