#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int minSetSize(vector<int>& arr) {

    //Map �� �̿��ؼ� �ߺ��ؼ� �����ϴ� ������ ������ �ľ��ߴ�
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
    //�迭 ũ��
    int n = arr.size();

    //�Ȱ��� ���ڰ� �� �� �����ߴ� ����, unordered map �� �̿��ؼ� ���Ѵ�
    //Hashing �� �� ���Ѱ�?
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++) {
        //map => ���� Ű�� [ ] �� �����ϸ�, �׳� �ϳ��� ���� �����
        //�� �ߴ� �� ����
        mp[arr[i]]++;
    }

    //heap �� ��� => ���� ���� ���� ���� ������� ����
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