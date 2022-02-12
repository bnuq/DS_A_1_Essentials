// Expected Time Complexity : O(N)


#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    // container 의 인덱스를 가리키는 것으로 이용
    int l = 0;
    int h = str.length() - 1;
 
    // Keep comparing characters while they are same
    // 끝까지 안돌고, 중간까지만 가면 되니까 두 index 가 서로 어긋날 때 까지만 하면 되는구나
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
}



bool my_isPalindrome(string str)
{
    // 나는 iterator 이용
    auto itrBegin = str.begin();
    auto itrEnd = str.end() - 1;

    // your code goes here
    while(itrBegin <= itrEnd) {
        if (*itrBegin != *itrEnd) return false;
        else {
            itrBegin++;
            itrEnd--;
        }
    }

    return true;
}