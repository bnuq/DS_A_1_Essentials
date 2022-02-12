#include<iostream>
using namespace std;

// Problem : Read N Strings and print the largest string. Each string can have upto 1000 characters.

int main(){

	int n;
	cin>>n;

	// n 입력을 위한, \n 을 버퍼에서 지우기 위해 사용
	cin.get();

	char sentence[1000];
	char largest[1000];

	int largest_len = 0;

	while(n--){
		// \n 까지 입력을 받고 \n 은 없애버린다
		cin.getline(sentence,1000);
		//cout<< sentence <<endl;
		int len = strlen(sentence);
		if(len > largest_len){
			largest_len = len;
			strcpy(largest,sentence);
		}
	}

	cout<<"Largest sentence is "<<largest <<endl;
	return 0;
}