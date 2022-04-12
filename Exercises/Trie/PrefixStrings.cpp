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

    // ���� �켱 Ž�� => temp ���� ��� ��带 ����
    void dfs(node*temp, vector<string> &v, string word ){
        
        // �ش� ��尡 ���ڿ� ���� ��� => ���ڿ� �ϼ� => ���ڿ��� ���Ϳ� �߰�
        if(temp->isTerminal){
            v.push_back(word);
        }

        // �����ϴ� ����� HashMap �� ������ ����ִ� ���
        // ���̻� �ؿ� ������ ���� ���� => ��
        if(temp->next.empty()){
            return;
        }

        // HashMap �� �����, �ؿ� �� �����ϴ� ���鿡 ���ؼ�
        for(auto p:temp->next){
            // �ش� ����� key ���� word �� ���̰�
            word.push_back(p.first);
        
            // dfs ����
            dfs(temp->next[p.first],v,word);
          
            // ���� ���� ����, �� ���� �̵�
            word.pop_back();
        }
        return;
    }

    

    // trie ���� str �� ���λ�� ������ ��� ���ڿ� ã��
    vector<string> find(string str){
        vector<string> v;
        node* temp=root; // root node ���� ����

        string word="";

        // str �� ù��° ���ں��� ����
        for(int i=0; i<str.length(); i++){
           
            // str ���� trie �� �������� ������, �׳� ����ִ� ���͸� ����
            if(temp->next.count(str[i])==0){
               return v;
            }
            // ����ϰ��� �ϴ� �ܾ� word
            word.push_back(str[i]);

            // ���� ���� �̵�
            temp=temp->next[str[i]];
        }// �ϴ� �־��� str �� ��� ã�Ҵ�
        
      
        
        // �ش� ��带 �������� dfs => ���� ��� ��带 ã�´�
        dfs(temp,v,word);

        // ���� �� ����
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
