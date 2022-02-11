#include<iostream>
using namespace std;



int main(){

	char paragraph[1000];

	// 입력은 엔터키를 누를 때까지 받는다 => 버퍼에 저장
	// 어디까지 읽을 지, 읽는 걸 멈출 문자를 지정할 수 있다
	// 여기서는 . 이 나오면 읽는 걸 멈춘다

	// 반대로 엔터를 눌러도 . 이 안나오면 계속 입력을 받는다
	cin.getline(paragraph,1000, '.');

	cout << paragraph <<endl;

}