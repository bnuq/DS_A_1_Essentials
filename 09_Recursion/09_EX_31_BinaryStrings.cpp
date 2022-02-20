/*
주어진 자릿 수를 가지는 모든 이진수 표현을 찾아서 리턴,
그런데 1이 연속하면 안되고 vector<string> 에 담아서 리턴
*/
//Expected Time Complexity: O(2^n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 내가 만든 버전 => 매 recursion 마다 vector<string> 을 리턴
// 다음 sub problem 을 해결한 결과인 vector<string> 을 받고나서 => 그걸 토대로 이번 단계 해결 => 새로운 vector<string> 을 리턴한다
// 앞 부분의 sub problem 을 해결했다 가정하고 => 이번 단계 해결
vector<string> makeBinaryStrings(int i, int n) { // i 번째 자리 결정, 총 n 자리
    vector<string> res{};
    if (i == 1) { // Base Case
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    else {
        // sub problem 먼저 해결 => 해결한 결과인 vector 를 받는다
        vector<string> vec = makeBinaryStrings(i - 1, n);

        // 현재 단계 작업
        for (const auto& x : vec) {
            if (x.back() == '0') {
                res.push_back(x + "0");
                res.push_back(x + "1");
            }
            else res.push_back(x + "0");
        }

        return res;
    }
}



/*
해설 버전 => 원하는 조건을 가진 string 을 하나하나 찾아가는 느낌
recursion 을 통해서, 원하는 조건의 문자열을 만들어 나가는 느낌 => 충족하면 넣고, 맞지 않으면 그냥 return 한다
만드는 건 만드는 거고, 넣을 지 말지는 또 다른 문제
*/
vector<string> v; // 최종 결과를 담는 벡터 => 전역 변수로 선언
void helper(string givenStr,int n,int i){
    if(i==n){   // 원하는 자릿수를 다 채웠으면, 전역 벡터에 저장
        v.push_back(givenStr);
        return;
    }

    string newStr{ givenStr }; // 이번에 작업하고자 하는 문자열 => 일단 앞에서 만든 문자열을 가져온다
    newStr.push_back('0'); // 기존 string 상태에 상관없이 0 은 항상 붙일 수 있다
    helper(newStr,n,i+1);  // 0 을 붙이고 나서 가능한 경우를 모두 찾는다


    // 이제 주어진 string 에 1 을 붙일 수 있는 지 없는 지 확인
    if(i>0 && givenStr.back()=='0'){ // 끝자리가 0 인 경우 => 붙일 수 있다
       givenStr.push_back('1');
       helper(givenStr,n,i+1);
    }
    else if(i==0){ // 아니면 아예 첫자리인 경우
        givenStr.push_back('1');
        helper(givenStr,n,i+1);
    }
    // 1 을 붙일 수 없는 경우 => 별다른 작업 없이 종료
    return;
}
vector<string> binaryStrings(int n){
     v.clear();
     string str;
     helper(str,n,0);
     return v;

}

int main() {
    vector<string> vec1{ makeBinaryStrings(4, 4) };
    for (const auto& x : vec1)
        cout << x << endl;

    cout << endl << endl;

    vector<string> vec2{ binaryStrings(4) };
    for (const auto& x : vec2)
        cout << x << endl;
}