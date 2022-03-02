#include <vector>
#include <queue>
#include <iostream>
using namespace std;



vector<char> firstnonrepeating(vector<char> str) {

    vector<char> res{};
    vector<int> isUnique(CHAR_MAX, 0);

    queue<char> q{};

    for (auto ch : str) {
        if (isUnique[ch - 'a'] == 0) { // 아직 한번도 안나왔다
            isUnique[ch - 'a'] = 1;
            q.push(ch);
            res.push_back(q.front());
        }
        else { // 이미 나왔었던 문자
            // 처음으로 중복되는 경우
            if (isUnique[ch - 'a'] == 1) isUnique[ch - 'a']++; // 값을 2로 만들어 => 2번째 나왔다
            // 큐에 추가하지 않고

            // 혹시 큐가 비었다면 0 출력
            if (q.empty()) res.push_back('0');
            else {
                // 혹시 큐 프론트와 같은 지 확인
                if (q.front() == ch) {
                    q.pop();

                    while (!q.empty() and isUnique[q.front() - 'a'] == 2) {
                        q.pop();
                    }

                    if (q.empty()) res.push_back('0');
                    else res.push_back(q.front());
                }
                else {
                    res.push_back(q.front());
                }
            }            
        }
    }

    return res;
}

int main() {
    vector<char> str{'a', 'a', 'b', 'c'};

    vector<char> res = firstnonrepeating(str);

    for (auto x : res)
        cout << x << " ";
    cout << endl;
}