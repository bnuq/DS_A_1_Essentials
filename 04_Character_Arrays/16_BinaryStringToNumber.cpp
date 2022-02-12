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
    
    // pow 함수를 쓰지 않고 그냥 뒤에서부터 계산 => 실제 계산하는 거처럼
    for (int i = len - 1; i >= 0; i--) {
        
        // 그냥 비교를 진짜 문자랑 하면 되는 거였어...
        if (num[i] == '1')
            dec_value += base;

        // 계산하지 않고 그냥 2배씩 제곱을 해
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
        char m = s[i]; // string 에서 char 을 가져온 뒤

        
        // char 값에서 '0' 을 빼서 아스키코드 -> 실제 숫자 값을 구했다
        if ((m - '0') == 1) {
            res += pow(2, n - 1 - i);
        }

    }

    return res;
}