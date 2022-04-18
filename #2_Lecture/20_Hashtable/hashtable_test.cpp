//File : Hashtable_test.cpp
#include<iostream>
#include "hashtable.h"
using namespace std;



int main(){

	Hashtable<int>  h;
	h.insert("Mango",100);
	h.insert("Apple",120);
	h.insert("Banana",140);
	h.insert("Orange",200);
	h.insert("Kiwi",210);
	h.insert("Papapya",220);
	h.insert("Litchi",30);
	h.print();


	//Search Test
	string fruit;
	//cin >> fruit;
	fruit = "Orange";

	//입력받은 과일 이름을 찾아
	int *price = h.search(fruit);
	//value 의 주소 값이 리턴된다
	if(price!=NULL) {
		cout<< "Price of " << fruit << " is "<< *price <<endl;
	}
	else{
		cout<<"Fruit is not present";
	}

	cout << endl << endl;


	//Erase Test
	h.eraseV2("Mango");
	h.eraseV2("Papapya");
	h.eraseV2("Kiwi");
	h.eraseV2("Kimchi");
	h.print();

	cout << endl << endl;


	//[] operator Overloading
	//Supercool functionality!
	h["newFruit"] = 200;
	cout<<"New fruit cost : "<<h["newFruit"]<<endl;
	
	//[] operator 를 통해서 값을 변경
	h["newFruit"] += 20;
	cout<<"New fruit updated cost : "<<h["newFruit"]<<endl;
	h.print();


	return 0;
}