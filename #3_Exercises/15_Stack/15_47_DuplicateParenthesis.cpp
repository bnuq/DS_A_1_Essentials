
//Expected Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

/*
    ) 에 대응되는 ( 를 스택에서 찾는데, 스택의 top 에 다른 문자가 없고 ( 가 바로 있다면, 
    두 괄호 사이에 아무것도 없다 or 그 이전에 ( ) 가 있었던 것이다 => 중복된 괄호라는 뜻이다
*/
bool duplicateParentheses(string str){
    
    stack<char> Stack;
  
    for (char ch : str)
    {
        if (ch == ')')
        {
            char top = Stack.top();
            Stack.pop();
  
            int elementsInside = 0;
            while (top != '(')
            {
                elementsInside++;
                top = Stack.top();
                Stack.pop();
            }
            if(elementsInside < 1) {
                return true;
            }
        }
  
        else
            Stack.push(ch);
    }
  
    return false;
    
}
