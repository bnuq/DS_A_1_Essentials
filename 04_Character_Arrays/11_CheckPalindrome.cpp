// Expected Time Complexity : O(N)


#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    // container �� �ε����� ����Ű�� ������ �̿�
    int l = 0;
    int h = str.length() - 1;
 
    // Keep comparing characters while they are same
    // ������ �ȵ���, �߰������� ���� �Ǵϱ� �� index �� ���� ��߳� �� ������ �ϸ� �Ǵ±���
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
    // ���� iterator �̿�
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