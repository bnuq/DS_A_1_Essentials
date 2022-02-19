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

/*
Given an array, and N number of queries. You have to check whether a subset whose sum is equal to
given number in queries exists in the array or not

Brute Force �ϰ� �����ϸ�, ���� �� �ִ� ��� �κ����տ� ���ؼ� ~ �׵��� ���� ��� ����ϰ� ~ ������ �صд�
����, ������ �յ鿡�� ���ϴ� query �� �ִ� �� ã�´�
��� �κ� ������ ����ϴ� ���� ~ O(2^n) �� ���̴� => ��� �Ұ���

���� ��� subsets �� ã�� ���� �Ұ����ϴ�
Bit Manipulation ���� �ذ� => bitset = bit �� ��Ƴ��� ����, �׳� ��Ʈ�� ����
bitset �� ǥ��� ���� => ���ؼ� ���� �� �ִ� ������ 1 �� ǥ���Ѵٰ� ����
*/
#include <bitset>
vector<bool> subsetSum(vector<int> num, vector<int> query)
{
    bitset<100> bitSet{}; // ������ �� ���� �� �ִ� ������ ǥ���� bitset
    bitSet.reset();       // �ϴ� ��� 0 ���� �ʱ�ȭ

    // bitset[i] => ���ؼ� i �� ���� �� �ִٸ� true ��, ���ٸ� false �� �����Ѵ�

    bitSet[0] = 1;     // �ƹ��͵� ������ ������ 0 �� ���� �� �����Ƿ�, �׻� bitset[0] = 1 �̴�

    // �־��� array �� �ִ� ������ �̿��ؼ� bitset �� ����� ����
    for (auto x : num)
        /*
        �־��� array ���� ���� �����´�. �� ���� �����ϴ� subset �� ���� �� �����Ƿ� bitset[i] = 1 �ε�,
        �ٵ� �ܼ� �������� �ʴ´�. �ٸ� ���� �߰��ϴ� ���� ���ϸ� ���ο� ���� �� �� �ִ�
        ���� left shift �� �̿��ؼ�, ������ ���鿡 �߰��ϴ� ���� ������ �� ���� �� �ִ� ������� �����Ѵ�
        �׸��� ������ OR �ؼ�, 1 �� ��� ��� => ���ؼ� ���� �� �ִ� ��� ���� ǥ���ϰ� �ȴ�
        */
        bitSet |= (bitSet << x);

    vector<bool> res{};
    for (auto x : query) {
        // bitset �� ���ؼ� ���� �� �ִ� ��� ���� ǥ���س����Ƿ�, query �� �䱸�ϴ� ����
        // bitset �� �ִ� �� ���� �� Ȯ�θ� �ؼ� ����� ������ �� �ִ�
        if (bitSet[x] == 1) res.push_back(true);
        else res.push_back(false);
    }

    return res;
}

int main() {
    cout << power(12, 25, 10007);
}