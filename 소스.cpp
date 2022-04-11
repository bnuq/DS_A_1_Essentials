#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> m{};

    for (const auto& x : completion) {
        m[x]++;
    }
    
    
    string answer = "";

    for (const auto& x : participant) {
        if (m[x] != 0) {
            m[x]--;
        }
        else {
            answer += x;
            break;
        }
    }


    return answer;
}


int main() {
    vector<string> parti{ "mislav", "stanko", "mislav", "ana" };
    vector<string> comp{ "stanko", "ana", "mislav" };

    cout << solution(parti, comp) << endl;
}