#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    queue<int> wT{};
    for (int i = 0; i < truck_weights.size(); i++) wT.push(truck_weights[i]);

    int curTime = 0;
    int total_weight = 0;
    int total_count = 0;
    queue<pair<int, int>> rT{};
    while (!wT.empty() || !rT.empty()) {
        curTime++;

        if (rT.empty()) {
            total_weight += wT.front();
            total_count++;
            
            rT.push({ wT.front(), curTime });
            wT.pop();
        }
        else {
            while (!rT.empty() and curTime - rT.front().second >= bridge_length) {
                total_weight -= rT.front().first;
                total_count--;

                rT.pop();
            }

            if (!wT.empty() and (total_count + 1 <= bridge_length) 
                and (total_weight + wT.front() <= weight)) {
                total_weight += wT.front();
                total_count++;

                rT.push({ wT.front(), curTime });
                wT.pop();
            }
        }

    }
    
    return curTime;
}

int main() {
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights{ 7,4,5,6 };

    cout << solution(bridge_length, weight, truck_weights) << endl;
}