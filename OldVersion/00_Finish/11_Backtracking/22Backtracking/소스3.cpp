#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getSubsets(vector<vector<int>>& res, vector<int>& nums, int index, vector<int>& temp) {
    if (index == nums.size()) {
        res.push_back(temp);
        return;
    }

    temp.push_back(nums[index]);
    getSubsets(res, nums, index + 1, temp);

    temp.pop_back();
    int next{ index + 1 };
    while (next < nums.size() and nums[index] == nums[next]) next++;
    getSubsets(res, nums, next, temp);
}

int main() {
    vector<vector<int>> res{};
    vector<int> nums{ 1,2,2 };
    vector<int> output{};

    getSubsets(res, nums, 0, output);

    sort(res.begin(), res.end(), [](const auto& e1, const auto& e2) {
        return e1 < e2;
        });

    for (auto x : res) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}