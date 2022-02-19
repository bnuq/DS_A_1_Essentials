#include <vector>
#include <iostream>
using namespace std;

/*
An array containing n numbers. All are present twice except one number
Find the unique number without taking any extra spaces
and in linear time

비트 연산자 => 논리 연산자 => 결합, 교환, 분배 법칙이 모두 성립한다
그리고 XOR => 같으면 0, 다르면 1, 0^x = x, x^x=0
*/
int xoring(vector<int> v)
{
    int res = 0;
    for (auto x : v)
        /*
        모든 요소들을 다 XOR 연산하면 => a^b^c^a^b^c^d
        교환, 결합 법칙 => 같은 것끼리 묶을 수 있어 => 0^0^0^d = d
        자연스럽게 짝이 없는 수만 남게 된다
        */
        res ^= x;
    return res;
}

int my_power(int x, int y, int mod)
{
    int ans{ 1 };
    // your code goes here
    while (y > 0) {
        int last_bit = (y & 1);
        if (last_bit) {
            if (x > mod) x = x % mod;
            ans *= x;
        }
        x = x * x;
        y = y >> 1;
    }

    cout << ans << endl;

    return ans % mod;
}

// Expected Time Complexity : O(Log N) 
// Hint: if a is even, than x^a can be written as (x^(a/2))*(x^(a/2))
 /*
 Calculate (x^y)%p
 Distributive Properties of Modulo
 (a+b) % c = ( (a%c) + (b%c) ) % c
 (a-b) % c = ( (a%c) - (b%c) ) % c
 (a*b) % c = ( (a%c) * (b%c) ) % c

 전체 계산 결과의 모듈러는, 각각 모듈러 결과를 이용해서 전체 계산을 한 것과 같다
 x^y 를 그냥 계산 => 값이 너무 커서 오버프로우 발생
 따라서 각 단계마다 모듈러 값을 이용해서, 전체 계산을 하도록 한다 => 그래도 전체 모듈러 결과에는 영향이 없다
 */
int power(int x, int y, int p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p; // 중간 계산 결과에 모듈러를 적용해도, 전체 계산이 같으므로 영향 없다

        y = y >> 1; // y = y/2
        x = (x * x) % p; // 역시 전체 계산에서 사용되는 부분이므로, 모듈러를 계산해도 문제없다
    }
    return res;
}
int main() {
    cout << power(12, 25, 10007);
}