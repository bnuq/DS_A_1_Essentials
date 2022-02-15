#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calcTotalMarks(vector<int> marks){
	return marks[0] + marks[1] + marks[2];
}

bool compare(pair<string,vector<int> > s1, pair<string,vector<int> > s2){
	vector<int> m1 = s1.second;
	vector<int> m2 = s2.second;
	
	// 왼쪽의 m1 이 왼쪽에 정렬된다고 생각
	// 따라서 총합이 큰 것 -> 작은 것 순서로 정렬하는 것
	return calcTotalMarks(m1) > calcTotalMarks(m2);
}


int main(){
	vector<pair<string,vector<int> > >  student_marks = {
		{"DRohan", {10,20,11}},
		{"CPrateek",{10,21,3}},
		{"BVivek",{4,5,6}},
		{"ARijul",{10,13,20}}
	};

	
	// 별 다른 comparator 가 없다면, 첫 번째 element 를 비교해서 정렬한다
	//sort(student_marks.begin(), student_marks.end());

	sort(student_marks.begin(),student_marks.end(),compare);

	for(auto s : student_marks){
		cout<< s.first <<" " <<calcTotalMarks(s.second)<<endl;
	}


	return 0;
}