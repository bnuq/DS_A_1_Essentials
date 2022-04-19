#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    // 각 유저가 신고한 유저를 기록하는 unordered set 을 만든다
    unordered_map<string, unordered_map<string, int>> eachReport{};
    unordered_map<string, int> totalReport{};

    for(string& rep : report) {
        vector<string> temp(2);

        istringstream iss(rep);

        iss >> temp[0] >> temp[1];

        // string buffer{};
        // while(getline(iss, buffer, ' ')) {
        //     temp.push_back(buffer);
        // }

        string reporting = temp[0];
        string reported = temp[1];

        if(eachReport[reporting][reported] == 0) {
            eachReport[reporting][reported] = 1;
            totalReport[reported]++;
        }
        else {
            // 해당 신고자는 이미 신고를 해서 할 작업이 없다
        }
    }

    
    vector<int> answer;


    for(const string& id : id_list) {

        int count = 0;

        for(auto& pp : eachReport[id]) {
            string reported = pp.first;

            if(totalReport[reported] >= k) {
                count++;
            }
        }

        answer.push_back(count);
    }



    for(auto x :totalReport) {
        cout << x.first << ", " << x.second << endl;
    }

    return answer;
}


int main() {
    
    vector<string> id_list{"muzi", "frodo", "apeach", "neo"};
    vector<string> report{"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};

        
    solution(id_list, report, 2);
}