// Expected Time Complexity : O(N)


#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    
	int count_=1;
    string ans;
	
    for(int i=0;i<chars.size();i++)
    {

        // �ϴ� ���� ���ڵ��� �ѹ��� ã�´�
        while(i<chars.size()-1 && chars[i+1] == chars[i])
        {
            count_++;
            i++;
        }

        // ���������� �� ���ڸ� �����ͼ� ~ ���ڿ��� ���� ~ ���� �߰��Ѵ�
        ans += chars[i];

        // 1���� �����ϴ� ���, �׳� �Ѿ
        if(count_ == 1)
        {
            continue;
        }

        // 1 �� �̻��̶�� ���ڸ� string ���� �ٲ㼭 ���ڿ��� �߰��ϰ� �ʱ�ȭ�Ѵ�
        ans += to_string(count_);
        count_ = 1;
    }
    

     // vector �� clear �޼��尡 �ֱ���
     chars.clear();
    

     // ���ڿ����� �ϳ��� �����ͼ� �ٽ� ���Ϳ� �߰�
     for(int i=0;i<ans.size();i++)
     {
          chars.push_back(ans[i]);
     } 
 
    return chars.size();
}


int my2_compress(vector<char>& chars) {
    string s{};

    // �����ϴ� �����, index, iterator �������� �����ϴ� �ž�
    auto itr = chars.begin();

    for (itr = chars.begin(); itr < chars.end(); itr++) {

        int count{ 1 };

        // �ٸ� ���ڰ� ���� ������ ã��
        while (itr < chars.end() - 1 && *itr == *(itr + 1)) {
            count++;
            itr++;
        }

        s += *itr;

        if (count != 1) {
            s += to_string(count);
        }
    }


    chars.clear();

    for (auto x : s) {
        chars.push_back(x);
    }

    return chars.size();
}



int my_compress(vector<char>& chars) {
    // your code goes here
    string s{};

    char ch{ chars[0] };
    int num{ 1 };

    for (int i = 1; i < chars.size(); i++) {
        if (chars[i] == ch) {
            num++;
        }
        else {
            if (num == 1) {
                s += ch;
                ch = chars[i];
                num = 1;
            }
            else {
                s += ch;
                s += to_string(num);
                ch = chars[i];
                num = 1;
            }
        }
    }
    s += ch;
    s += to_string(num);

    chars.erase(chars.begin(), chars.end());

    for (auto x : s) {
        chars.push_back(x);
    }

    return s.size();

}