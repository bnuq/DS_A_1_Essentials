#include<bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    
    // �ش� �濡 �湮�ߴ� �� ���θ�, �ؽ� ���� ���ؼ� ���
    unordered_map<int,bool> map;
        
    // ��ü ���� ����
    int n = rooms.size();

    for(int i=0; i<n; i++){
        // �ؽø� �ʱ�ȭ => �׳� key �� ���⸸ �ص�, �ϴ� ������ Entry �� �����
        map[i] = false;
    }

    // �Ȱ��� bfs �� ���ؼ� ��ü �׷��� ��ȸ
    queue<int> q;
    q.push(0); // ó�� ���� ���

    while(!q.empty()){

        // ���� ť�� ����ִ� ���鿡 ���ؼ� ��� �����ϰڴ�
        // �ٵ� �� ������ �� �ʿ��Ѱ�?
        // ������ ��ü ť�� ����� �� Ȯ���ϴϱ�, �� ������ �ʿ� ���� �� ������
        int k=q.size();
        while(k--){
            int a=q.front();
            q.pop();
            map[a]=true; // �湮 ��� ǥ��

            for(int j=0; j<rooms[a].size() && rooms[a].size()!=0; j++){
                
                // ���� �̿��� �湮���� ���� ���� ���, ť�� �߰� => ���� ����
                if(map[rooms[a][j]]==false){
                    q.push(rooms[a][j]);
                }     
            }
        }
    }
    for(auto i:map){
        if(i.second==false){
            return false;
        }
    }
    return true;
}


bool MycanVisitAllRooms(vector<vector<int>>& rooms) {

    int roomNum = rooms.size();
    vector<bool> visit(roomNum, false);


    // bfs �� ���ؼ�, ��ü �׷����� traversal

    queue<int> q{};

    q.push(0);

    while (!q.empty()) {
        int curRoom = q.front();
        q.pop();

        visit[curRoom] = true;

        for (auto key : rooms[curRoom]) {
            if (visit[key] == false) {
                q.push(key);
            }
        }
    }

    for (auto res : visit) {
        if (res == false) return false;
    }

    return true;
}