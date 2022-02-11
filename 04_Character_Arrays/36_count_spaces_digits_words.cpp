#include<iostream>
using namespace std;
// Given a sentence, count the number of alphabets, digits & spaces in the sentence





int main(){


	//store and then count
	// read one by one and then count 

	char ch;

	ch = cin.get();

	//Count 
	int alpha = 0;
	int space = 0;
	int digit = 0;

	while(ch!='\n'){

		// 문자 값으로 범위 확인
		if(ch>='0' and ch<='9'){
			digit++;
		}
		else if((ch>='a' and ch<='z') or (ch>='A' and ch<='Z')){
			alpha++;
		}
		// 공백은 한칸 공백 or 탭 공백
		else if(ch==' ' or ch=='\t'){
			space++;
		}

		ch = cin.get();
	}

	cout<<"Total Alphabets "<<alpha<<endl;
	cout<<"Total Digits "<<digit<<endl;
	cout<<"Total Space "<<space<<endl;
	
	return 0;

}