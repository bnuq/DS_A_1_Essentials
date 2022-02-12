// Expected Time Complexity : O(N)


#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    
	int count_=1;
    string ans;
	
    for(int i=0;i<chars.size();i++)
    {

        // 일단 같은 문자들을 한번에 찾는다
        while(i<chars.size()-1 && chars[i+1] == chars[i])
        {
            count_++;
            i++;
        }

        // 마지막으로 센 문자를 가져와서 ~ 문자열에 더해 ~ 끝에 추가한다
        ans += chars[i];

        // 1개만 존재하는 경우, 그냥 넘어가
        if(count_ == 1)
        {
            continue;
        }

        // 1 개 이상이라면 숫자를 string 으로 바꿔서 문자열에 추가하고 초기화한다
        ans += to_string(count_);
        count_ = 1;
    }
    

     // vector 에 clear 메서드가 있구나
     chars.clear();
    

     // 문자열에서 하나씩 가져와서 다시 벡터에 추가
     for(int i=0;i<ans.size();i++)
     {
          chars.push_back(ans[i]);
     } 
 
    return chars.size();
}


int my2_compress(vector<char>& chars) {
    string s{};

    // 조사하는 대상을, index, iterator 관점에서 생각하는 거야
    auto itr = chars.begin();

    for (itr = chars.begin(); itr < chars.end(); itr++) {

        int count{ 1 };

        // 다른 문자가 나올 때까지 찾아
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