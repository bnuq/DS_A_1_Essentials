#include<iostream>
using namespace std;

// Problem : Read N Strings and print the largest string. Each string can have upto 1000 characters.

int main(){

	int n;
	cin>>n;

	// n �Է��� ����, \n �� ���ۿ��� ����� ���� ���
	cin.get();

	char sentence[1000];
	char largest[1000];

	int largest_len = 0;

	while(n--){
		// \n ���� �Է��� �ް� \n �� ���ֹ�����
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