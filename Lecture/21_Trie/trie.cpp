#include<iostream>
#include "trie.h"
using namespace std;


int main(){
	
	string words[] = {"hello","he","apple","aple","news"};
	Trie t;

	for(const string& word : words){
		t.insert(word);
	}

	string key;
	//cin>>key;

	key = "apple";
	cout<< boolalpha << t.search(key) <<endl;
	

	return 0;
}