//Expected Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

/*
    주어진 숫자를 역순서로 출력하기
    낮은 자리부터 스택에 쌓아서 => 높은 자리를 나중에 넣는다
    그러면 나중에 꺼낼때는
    높은 자리부터 꺼내서 => 낮은 자리 수를 나중에 처리
*/
int reverse(int n){
    
    int number = n;
    stack <int> st;
    while (number != 0) {
        st.push(number % 10);   // 낮은 자리의 수부터 스택에 넣는다
        number = number / 10;
    }
    
    int rev = 0;
    int i = 1;      
    while (!st.empty()) {
        rev = rev + (st.top() * i); // 높은 자리의 수부터 꺼내서 값을 계산한다
        st.pop();
        i = i * 10; // 꺼낼 때마다 한 자리씩 자리가 높아진다
    }
      
    return rev;
}