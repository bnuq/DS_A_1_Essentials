#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> my_intersection(vector<int>& nums1, vector<int>& nums2) {

    unordered_set<int> setFor1{};
    set<int> finalSet{};

    for (const int& i : nums1) {
        setFor1.insert(i);
    }

    for (const int& i : nums2) {
        //찾음 => 겹친다 => 넣는다
        if (setFor1.find(i) != setFor1.end()) {
            finalSet.insert(i);
        }
    }

    vector<int> res{};
    for (const int& i : finalSet) {
        res.push_back(i);
    }

    return res;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    //unordered map 을 사용하네
    unordered_map<int, int> map;
    vector<int> result;

    for (int i = 0; i < nums1.size(); i++) {
        /*
            map 의 [] operator 사용
            해당 key 노드가 존재하지 않으면, 자동으로 하나 생성해준다
            
            찾거나, 생성한 다음에
            값을 1개 증가시키기
        */        
        map[nums1[i]]++;
    }

    for (int i = 0; i < nums2.size(); i++) {
        /*
            [] operator 사용, 없으면 하나 생성
            근데 값을 확인 => 값이 존재하는 경우, 이미 있는 경우에 대해서만
            추가 처리 => intersection 이니까
        */
        if (map[nums2[i]] > 0) {
            result.push_back(nums2[i]);
            map[nums2[i]] = 0;
        }
    }

    //vector 정렬
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    vector<int> nums1{ 1,2,3,1,2,3,45,5,3 };
    vector<int> nums2{ 3,2,2,2,1,2,2,1,9 };

    vector<int> res = intersection(nums1, nums2);

    for (auto x : res) {
        cout << x << endl;
    }
}