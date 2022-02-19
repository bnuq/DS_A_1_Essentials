#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 12.
string compression 문제
*/
int my2_compress(vector<char>& chars) {
    string s{};
    // 조사하는 대상을, index, iterator 관점에서 생각하는 거야
    auto itr = chars.begin();
    for (itr = chars.begin(); itr < chars.end(); itr++) {
        int count{ 1 };
        // 반복문 안에서 반복문 => 한 번의 루프에서 꼭 요소 하나만 처리할 필요는 없다
        // 같은 문자들이 붙어 있는 경우를 처리하는 걸 => 하나의 루프에서 처리
        while (itr < chars.end() - 1 && *itr == *(itr + 1)) {
            count++;
            itr++; // 여기서 iterator 를 추가 조작
        }
        s += *itr;
        if (count != 1) {
            s += to_string(count);
        }
    }
    // vector :: clear() => vector 를 완전 초기화 하는 메서드
    chars.clear();
    for (auto x : s) {
        chars.push_back(x);
    }
    return chars.size();
}

/* 14.
문자열 내에서 중복되는 문자를 모두 제거하라
*/
#include <set>
string removeDuplicate(string s) {
    // 이게 자료구조를 이용하는 방법이지
    // set 에 넣는다 => binary tree 구조, 중복 keys 는 허용하지 않는다, 자동 정렬
    // iterator 를 이용해서, vector => set 에 넣을 수 있다
    // iterator 를 이용해서 초기화 하는 방법
    set<char> ss(s.begin(), s.end());
    set<char> sss{ s.begin(), s.end() };

    // vector 로도 가능하다
    vector<char> vec{ 'a', 'a', 'a', 'a', 'a', 'b', 'e', 'a', 'a'};
    set<char> ssss{ vec.begin(), vec.end() };

    string str;
    for (auto x : sss)
        str.push_back(x);

    for (auto x : ssss)
        cout << x << " , ";

    return str;
}

/* 15
aeiou 만 string 에서 뽑아내라
*/
#include <algorithm>
string my_vowel(string S) {
    string res{};

    // for_each 알고리즘 한번 사용해 봤음
    for_each(S.begin(), S.end(), [&res](const auto& e) {
        if (e == 'a' or e == 'e' or e == 'i' or e == 'o' or e == 'u')
            res += e;
        });
    return res;
}


int main() {
    string s{ "weklerklwmfwen" };
    cout << endl << removeDuplicate(s) << endl;
}