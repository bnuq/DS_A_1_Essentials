#include <bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    unordered_map<char,node*> next;
    bool isTerminal;
    
    node(char a){
        ch=a;
        bool isTerminal=false;
    }
};


class Trie{
public:
    node*root= new node('\0');
    
    void insert(string str){

        node* temp=root;

        for(int i=0; i<str.length(); i++) {

           if(temp->next.count(str[i])==0) {
               temp->next[str[i]]=new node(str[i]);
           }
           temp=temp->next[str[i]];
        }
        temp->isTerminal=true;
        return;
    }

    // 깊이 우선 탐색 => temp 밑의 모든 노드를 조사
    void dfs(node*temp, vector<string> &v, string word ){
        
        // 해당 노드가 문자열 끝인 경우 => 문자열 완성 => 문자열을 벡터에 추가
        if(temp->isTerminal){
            v.push_back(word);
        }

        // 조사하는 노드의 HashMap 이 완전히 비어있는 경우
        // 더이상 밑에 내려갈 곳이 없다 => 끝
        if(temp->next.empty()){
            return;
        }

        // HashMap 에 연결된, 밑에 더 존재하는 노드들에 대해서
        for(auto p:temp->next){
            // 해당 노드의 key 값을 word 에 붙이고
            word.push_back(p.first);
        
            // dfs 조사
            dfs(temp->next[p.first],v,word);
          
            // 떼어 내고 다음, 옆 노드로 이동
            word.pop_back();
        }
        return;
    }

    

    // trie 에서 str 을 접두사로 가지는 모든 문자열 찾기
    vector<string> find(string str){
        vector<string> v;
        node* temp=root; // root node 부터 시작

        string word="";

        // str 의 첫번째 문자부터 조사
        for(int i=0; i<str.length(); i++){
           
            // str 조차 trie 에 존재하지 않으면, 그냥 비어있는 벡터를 리턴
            if(temp->next.count(str[i])==0){
               return v;
            }
            // 출력하고자 하는 단어 word
            word.push_back(str[i]);

            // 다음 노드로 이동
            temp=temp->next[str[i]];
        }// 일단 주어진 str 은 모두 찾았다
        
      
        
        // 해당 노드를 기준으로 dfs => 밑의 모든 노드를 찾는다
        dfs(temp,v,word);

        // 정렬 후 리턴
        sort(v.begin(),v.end());
        return v;
    }

    
    

};



vector<string> findPrefixStrings(vector<string> words, string prefix){
        Trie t;
        for(auto s:words){
            t.insert(s);
        }
        vector<string> res=t.find(prefix);
        return res;
    }
