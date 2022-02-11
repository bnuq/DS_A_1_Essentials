#include<iostream>
using namespace std;
	
/*
	For C - Style String
*/
/*
	strcpy_s 하고 strcat_s 가 받는 인자가 줄어들었다, 더 간단해졌다
	C++20 들어오면서 더 간소화 됐나??
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



	//Compare : string 이 같은지 아닌지
	// 같을 때 0 리턴
	// a < b => 음수 리턴
	// a > b => 양수 리턴
	cout << strcmp(a,b) <<endl;
	//strcmp
	
	char web[100] = "www.";
	char domain[] = "codingminutes.com";

	
	// 두 문자열을 합치는 역할 strcat_s(a, b) == a + b
	// 그런데 합친 결과인 const char* 을 복사해서 리턴하는 게 아니고, a 배열에 저장한다
	// 그래서 a 배열 크기가 작으면 버퍼 오버플로우가 발생한다
	// 값을 리턴하는 함수가 아니다
	strcat_s(web, domain);
	strcpy_s(b, web);
	cout << b << endl;


	cout << strcmp(b,a) <<endl;



	return 0;
}