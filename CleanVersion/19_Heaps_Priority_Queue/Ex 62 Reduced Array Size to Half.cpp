#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int minSetSize(vector<int>& arr) {

    //Map 을 이용해서 중복해서 등장하는 숫자의 개수를 파악했다
    map<int, int> arrMap{};
    for (const auto& x : arr) {
        if (arrMap.find(x) == arrMap.end()) {
            arrMap.insert({ x, 1 });
        }
        else arrMap[x]++;
    }

    for (auto x : arrMap) {
        auto [key, value] = x;

        cout << key << " , " << value << endl;
    }
        
    
    priority_queue<int> maxHeap{};
    
    for (auto x : arrMap) {
        maxHeap.push(x.second);
    }


    int halfSize = arr.size() / 2;
    int total{ 0 }, count{ 0 };

    while (!maxHeap.empty()) {
        total += maxHeap.top();
        
        maxHeap.pop();        
        count++;

        if (total >= halfSize) break;
    }

    return count;
}

int main() {
    vector<int> arr{ 3,3,3,3,5,5,5,2,2,7 };
    cout << minSetSize(arr) << endl;
}


#include <unordered_map>
int solution(vector<int>& arr) {
    //배열 크기
    int n = arr.size();

    //똑같은 숫자가 몇 번 등장했는 지를, unordered map 을 이용해서 구한다
    //Hashing 이 더 편리한가?
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++) {
        //map => 없는 키에 [ ] 로 접근하면, 그냥 하나를 새로 만든다
        //고 했던 거 같아
        mp[arr[i]]++;
    }

    //heap 에 담아 => 가장 많이 나온 개수 순서대로 정리
    priority_queue<int> q;
    for (auto pair : mp) {
        q.push(pair.second);
    }

    int sum = 0;
    int cnt = 0;
    while (n - sum > n / 2) {
        sum += q.top();
        q.pop();
        cnt++;

    }
    
    return cnt;
}