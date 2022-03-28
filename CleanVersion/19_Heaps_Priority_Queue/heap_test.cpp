#include<iostream>
#include "heap.h"
using namespace std;


int main(){

	//int marks[] = {90,80,12,13,15,56,94};
	int marks[] = { 90,80,12,13,15,56,94,24,12,94,87,28,99,38 };

	//Heap<int> h{true};	//min heap
	Heap<int> h{ false };	//max heap

	for(int x:marks){
		h.push(x); //logn
	}

	while(!h.empty()){
		cout<< h.top() <<endl;
		h.pop(); //logn
	}


	return 0;
}


