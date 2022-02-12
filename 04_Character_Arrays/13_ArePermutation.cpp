//Expected Time Complexity= O(N log N)
//Hint: Permuatations are just different arrangements of same alphabets. Can you make the arrangement same?


#include <bits/stdc++.h>
using namespace std;
 
bool arePermutation(string str1, string str2)
{
    // Get lenghts of both strings
    int n1 = str1.length();
    int n2 = str2.length();
 
    // If length of both strings is not same,
    // then they cannot be Permutation
    if (n1 != n2)
      return false;
 
    // Sort both strings
    // Sort 하는 접근은 동일
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
 
    
    // string 을 돌면서 하나씩 비교했구나
    // 근데 STL 이니까 string 에서는 비교 연산자를 지원한다 => 그냥 == 연산자 사용
    // Compare sorted strings
    for (int i = 0; i < n1;  i++)
       if (str1[i] != str2[i])
         return false;
 
    return true;
}