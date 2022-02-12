Expected Time Complexity : O(N)


#include <iostream>
#include <string>
using namespace std;
 
// Function to convert binary to decimal
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    
    // pow �Լ��� ���� �ʰ� �׳� �ڿ������� ��� => ���� ����ϴ� ��ó��
    for (int i = len - 1; i >= 0; i--) {
        
        // �׳� �񱳸� ��¥ ���ڶ� �ϸ� �Ǵ� �ſ���...
        if (num[i] == '1')
            dec_value += base;

        // ������� �ʰ� �׳� 2�辿 ������ ��
        base = base * 2;
    }
 
    return dec_value;
}
 

int my_binaryToDecimal(string s)
{
    int n = s.size();
    int res{ 0 };

    // your code goes here
    for (int i = 0; i < n; i++) {
        char m = s[i]; // string ���� char �� ������ ��

        
        // char ������ '0' �� ���� �ƽ�Ű�ڵ� -> ���� ���� ���� ���ߴ�
        if ((m - '0') == 1) {
            res += pow(2, n - 1 - i);
        }

    }

    return res;
}