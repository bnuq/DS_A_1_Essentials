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

/*
Given an array, and N number of queries. You have to check whether a subset whose sum is equal to
given number in queries exists in the array or not

Brute Force 하게 접근하면, 만들 수 있는 모든 부분집합에 대해서 ~ 그들의 합을 모두 계산하고 ~ 저장을 해둔다
이후, 가능한 합들에서 원하는 query 가 있는 지 찾는다
모든 부분 집합을 계산하는 과정 ~ O(2^n) 일 것이다 => 계산 불가능

직접 모든 subsets 를 찾는 것은 불가능하다
Bit Manipulation 으로 해결 => bitset = bit 를 모아놓은 구조, 그냥 비트라 생각
bitset 을 표라고 생각 => 더해서 만들 수 있는 값들을 1 로 표시한다고 생각
*/
#include <bitset>
vector<bool> subsetSum(vector<int> num, vector<int> query)
{
    bitset<100> bitSet{}; // 더했을 때 만들 수 있는 값들을 표시할 bitset
    bitSet.reset();       // 일단 모두 0 으로 초기화

    // bitset[i] => 더해서 i 를 만들 수 있다면 true 를, 없다면 false 를 저장한다

    bitSet[0] = 1;     // 아무것도 더하지 않으면 0 을 만들 수 있으므로, 항상 bitset[0] = 1 이다

    // 주어진 array 에 있는 값들을 이용해서 bitset 에 기록을 시작
    for (auto x : num)
        /*
        주어진 array 에서 값을 가져온다. 그 값만 포함하는 subset 을 만들 수 있으므로 bitset[i] = 1 인데,
        근데 단순 대입하지 않는다. 다른 값에 추가하는 값을 더하면 새로운 값을 얻어낼 수 있다
        따라서 left shift 를 이용해서, 기존의 값들에 추가하는 값을 더했을 때 얻을 수 있는 값들까지 포함한다
        그리고 기존과 OR 해서, 1 을 모두 살려 => 더해서 얻을 수 있는 모든 값을 표시하게 된다
        */
        bitSet |= (bitSet << x);

    vector<bool> res{};
    for (auto x : query) {
        // bitset 에 더해서 얻을 수 있는 모든 값을 표시해놨으므로, query 가 요구하는 값이
        // bitset 에 있는 지 없는 지 확인만 해서 결과를 리턴할 수 있다
        if (bitSet[x] == 1) res.push_back(true);
        else res.push_back(false);
    }

    return res;
}

int main() {
    cout << power(12, 25, 10007);
}