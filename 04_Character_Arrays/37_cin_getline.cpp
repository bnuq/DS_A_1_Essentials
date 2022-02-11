#include<iostream>
using namespace std;



int main(){

	char sentence[1000];

	// 최대 입력받을 수 있는 메모리를 같이 적는다
	cin.getline(sentence,1000);

	cout << sentence <<endl;

	cout << strlen( sentence ) << endl;
	cout << sizeof(sentence) << endl;

}