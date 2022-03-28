#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


//row �� �Ŀ��� ���ϴ� function object
struct toCompare {
    bool operator()(const pair<int, int>& e1, const pair<int, int>& e2) {
        //���ʿ� ���� �� ������ ����
        //�Ŀ��� ū ���� ���� ���� �Ѵ�, ���� ���� ������ ���� �Ѵ�
        if (e1.second == e2.second) {
            return e1.first < e2.first; //row ��ȣ�� ���� ���� ���� ���̴�
        }
        else  return e1.second < e2.second; //soldier ������ ���� ���� ���� ���̴�
    }

};


vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    
    //�� row ��ȣ�� soldiers ������ �����Ѵ�
    vector<pair<int, int>> numOfSol{};

    for(int i = 0; i < mat.size(); i++) {
        int sum{ 0 };
        
        for (const auto& val : mat[i]) {
            if (val == 1) sum++;
            else break;
        }

        numOfSol.push_back({i, sum});
    }

    //row ��ȣ�� �� row �� soldiers ������ k �� �����ϴ� Heap �� �����
    priority_queue<pair<int, int>, vector<pair<int, int>>, toCompare>
        maxheap(numOfSol.begin(), numOfSol.begin() + k);

    
    //�Ŀ� �񱳸� ���ؼ�
    toCompare cmp{};


    for (int i = k; i < mat.size(); i++) {
        
        //�̹��� �����ϴ� pair
        auto val = numOfSol[i];

        //Heap �� ����⺸�� �Ŀ��� ũ�ٸ�, ������ �ʿ� ����
        //val �� Heap �� ����⺸�� �Ŀ��� �۴ٸ�
        if (cmp(val, maxheap.top())) {
            //Heap �� ����� ����
            maxheap.pop();
            //val �� �ִ´�
            maxheap.push(val);
        }
    }

    //stack ���� ���� ������ => �־�ü���� ������ ����
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



//��ü���� �帧 ���
vector<int> sol_kWeakestRows(vector<vector<int>>& mat, int k) {
    
    /*
        pair �� ���ؼ�, �⺻���� ���Լ��� ���ǵǾ� �ִ�

        first �� ���ؼ� ���ϴ� ���� �켱������ ������
        first �� ���� ��� second �񱳸� �Ѵ�

        ���⼭�� greater ���
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