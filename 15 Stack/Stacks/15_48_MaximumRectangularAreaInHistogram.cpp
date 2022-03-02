
//Expected Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;
 
int getMaxArea(vector<int> hist)
{
    int n = hist.size();
    stack<int> s;
 
    int max_area = 0; 
    int tp; 
    int area_with_top;
 
    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i]) // 값이 더 크면 스택의 위에 넣는다
            s.push(i++);
        else // 기존 스택에 있던 값이 더 커
        {
            tp = s.top(); // 기존 스택 top value
            s.pop();  
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i :
                                i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}