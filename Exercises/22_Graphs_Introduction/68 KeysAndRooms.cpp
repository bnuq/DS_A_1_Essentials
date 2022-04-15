#include<bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    
    // 해당 방에 방문했는 지 여부를, 해시 맵을 통해서 기록
    unordered_map<int,bool> map;
        
    // 전체 방의 개수
    int n = rooms.size();

    for(int i=0; i<n; i++){
        // 해시맵 초기화 => 그냥 key 를 쓰기만 해도, 일단 무조건 Entry 가 생긴다
        map[i] = false;
    }

    // 똑같이 bfs 를 통해서 전체 그래프 순회
    queue<int> q;
    q.push(0); // 처음 시작 노드

    while(!q.empty()){

        // 현재 큐에 들어있는 값들에 대해서 모두 실행하겠다
        // 근데 이 조건이 꼭 필요한가?
        // 어차피 전체 큐가 비었는 지 확인하니까, 이 조건은 필요 없을 거 같은데
        int k=q.size();
        while(k--){
            int a=q.front();
            q.pop();
            map[a]=true; // 방문 기록 표시

            for(int j=0; j<rooms[a].size() && rooms[a].size()!=0; j++){
                
                // 다음 이웃이 방문하지 않은 방인 경우, 큐에 추가 => 순서 예약
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


    // bfs 를 통해서, 전체 그래프를 traversal

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