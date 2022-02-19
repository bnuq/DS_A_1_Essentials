#include <vector>
#include <iostream>
using namespace std;

/*
An array containing n numbers. All are present twice except one number
Find the unique number without taking any extra spaces
and in linear time

��Ʈ ������ => �� ������ => ����, ��ȯ, �й� ��Ģ�� ��� �����Ѵ�
�׸��� XOR => ������ 0, �ٸ��� 1, 0^x = x, x^x=0
*/
int xoring(vector<int> v)
{
    int res = 0;
    for (auto x : v)
        /*
        ��� ��ҵ��� �� XOR �����ϸ� => a^b^c^a^b^c^d
        ��ȯ, ���� ��Ģ => ���� �ͳ��� ���� �� �־� => 0^0^0^d = d
        �ڿ������� ¦�� ���� ���� ���� �ȴ�
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

 ��ü ��� ����� ��ⷯ��, ���� ��ⷯ ����� �̿��ؼ� ��ü ����� �� �Ͱ� ����
 x^y �� �׳� ��� => ���� �ʹ� Ŀ�� �������ο� �߻�
 ���� �� �ܰ踶�� ��ⷯ ���� �̿��ؼ�, ��ü ����� �ϵ��� �Ѵ� => �׷��� ��ü ��ⷯ ������� ������ ����
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
            res = (res * x) % p; // �߰� ��� ����� ��ⷯ�� �����ص�, ��ü ����� �����Ƿ� ���� ����

        y = y >> 1; // y = y/2
        x = (x * x) % p; // ���� ��ü ��꿡�� ���Ǵ� �κ��̹Ƿ�, ��ⷯ�� ����ص� ��������
    }
    return res;
}
int main() {
    cout << power(12, 25, 10007);
}