#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct pairCompare {
    bool operator()(const pair<int, int>& e1, const pair<int, int>& e2) {
        //점수가 큰게 위로와야 하니까, 왼쪽 = 밑 은 점수가 작아야 한다
        return e1.second < e2.second;
    }
};


vector<string> findRelativeRanks(vector<int>& score) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare>
        heap{};

    for (int i = 0; i < score.size(); i++) {
        heap.push({ i, score[i] });
    }

    vector<string> res{};
    res.resize(score.size());

    int name = heap.top().first;
    heap.pop();
    res[name] = "Gold Medal";

    name = heap.top().first;
    heap.pop();
    res[name] = "Silver Medal";

    name = heap.top().first;
    heap.pop();
    res[name] = "Bronze Medal";

    int count{ 4 };
    while (!heap.empty()) {
        name = heap.top().first;
        heap.pop();

        res[name] = to_string(count++);
    }

    return res;
}


int main() {
    vector<int> score{ 5,4,13,2,91 };
    vector<string> res = findRelativeRanks(score);

    for (auto x : res)
        cout << x << endl;
}