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
	
	// ������ m1 �� ���ʿ� ���ĵȴٰ� ����
	// ���� ������ ū �� -> ���� �� ������ �����ϴ� ��
	return calcTotalMarks(m1) > calcTotalMarks(m2);
}


int main(){
	vector<pair<string,vector<int> > >  student_marks = {
		{"DRohan", {10,20,11}},
		{"CPrateek",{10,21,3}},
		{"BVivek",{4,5,6}},
		{"ARijul",{10,13,20}}
	};

	
	// �� �ٸ� comparator �� ���ٸ�, ù ��° element �� ���ؼ� �����Ѵ�
	//sort(student_marks.begin(), student_marks.end());

	sort(student_marks.begin(),student_marks.end(),compare);

	for(auto s : student_marks){
		cout<< s.first <<" " <<calcTotalMarks(s.second)<<endl;
	}


	return 0;
}