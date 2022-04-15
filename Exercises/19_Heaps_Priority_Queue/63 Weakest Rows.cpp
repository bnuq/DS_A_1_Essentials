#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


//row 의 파워를 비교하는 function object
struct toCompare {
    bool operator()(const pair<int, int>& e1, const pair<int, int>& e2) {
        //왼쪽에 오는 게 밑으로 간다
        //파워가 큰 것이 위로 가야 한다, 약한 것이 밑으로 가야 한다
        if (e1.second == e2.second) {
            return e1.first < e2.first; //row 번호가 낮은 것이 약한 것이다
        }
        else  return e1.second < e2.second; //soldier 개수가 작은 것이 약한 것이다
    }

};


vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    
    //각 row 번호와 soldiers 개수를 저장한다
    vector<pair<int, int>> numOfSol{};

    for(int i = 0; i < mat.size(); i++) {
        int sum{ 0 };
        
        for (const auto& val : mat[i]) {
            if (val == 1) sum++;
            else break;
        }

        numOfSol.push_back({i, sum});
    }

    //row 번호와 그 row 의 soldiers 개수를 k 개 저장하는 Heap 을 만든다
    priority_queue<pair<int, int>, vector<pair<int, int>>, toCompare>
        maxheap(numOfSol.begin(), numOfSol.begin() + k);

    
    //파워 비교를 위해서
    toCompare cmp{};


    for (int i = k; i < mat.size(); i++) {
        
        //이번에 조사하는 pair
        auto val = numOfSol[i];

        //Heap 의 꼭대기보다 파워가 크다면, 조사할 필요 없다
        //val 이 Heap 의 꼭대기보다 파워가 작다면
        if (cmp(val, maxheap.top())) {
            //Heap 의 꼭대기 제거
            maxheap.pop();
            //val 을 넣는다
            maxheap.push(val);
        }
    }

    //stack 으로 값을 뒤집어 => 최약체부터 나오게 하자
    stack<int> s{};

    while (!maxheap.empty()) {
        s.push(maxheap.top().first);
        maxheap.pop();
    }

    vector<int> res{};

    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }

    return res;
}



int main() {
    vector<vector<int>> mat{
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };

    vector<int> res = kWeakestRows(mat, 3);


    for (auto x : res)
        cout << x << endl;
}



//전체적인 흐름 비슷
vector<int> sol_kWeakestRows(vector<vector<int>>& mat, int k) {
    
    /*
        pair 에 대해서, 기본적인 비교함수가 정의되어 있다

        first 에 대해서 비교하는 것이 우선순위를 가지고
        first 가 같은 경우 second 비교를 한다

        여기서는 greater 사용
    */
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; //Min-heap
    for (int i = 0; i < mat.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                count++; //Counting the number of soldiers in each case
            }
        }
        pq.push(make_pair(count, i));
    }
    vector<int> x;
    while (k > 0)
    {
        pair<int, int> temp = pq.top();
        x.push_back(temp.second);
        pq.pop();
        k--;
    }
    return x;
}