//Expected Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

/*
    �־��� ���ڸ� �������� ����ϱ�
    ���� �ڸ����� ���ÿ� �׾Ƽ� => ���� �ڸ��� ���߿� �ִ´�
    �׷��� ���߿� ��������
    ���� �ڸ����� ������ => ���� �ڸ� ���� ���߿� ó��
*/
int reverse(int n){
    
    int number = n;
    stack <int> st;
    while (number != 0) {
        st.push(number % 10);   // ���� �ڸ��� ������ ���ÿ� �ִ´�
        number = number / 10;
    }
    
    int rev = 0;
    int i = 1;      
    while (!st.empty()) {
        rev = rev + (st.top() * i); // ���� �ڸ��� ������ ������ ���� ����Ѵ�
        st.pop();
        i = i * 10; // ���� ������ �� �ڸ��� �ڸ��� ��������
    }
      
    return rev;
}