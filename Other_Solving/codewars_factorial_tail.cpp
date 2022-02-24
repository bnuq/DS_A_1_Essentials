#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// fixme
void GetPrimes(vector<int>& vec, int num) {
    int limit = static_cast<int>(sqrt(num));
    for (int i = 2; i <= limit; i++) {
        while (num % i == 0) {
            vec[i]++;
            num /= i;
        }
        if (num == 1) return;
    }
    vec[num]++;
    return;
}


int Zeroes(int base, int number)
{
    vector<int> basePrime(base+1, 0);
    vector<int> numPrime(number+1, 0);

    GetPrimes(basePrime, base);

    for (int i = 2; i <= number; i++) {
        GetPrimes(numPrime, i);
    }

    int minVal{ number };
    for (int i = 2; i <= base; i++) {
        if (basePrime[i] == 0) continue;

        int temp{ numPrime[i] / basePrime[i] };
        //cout << i << " is " << temp << endl;
        minVal = min(minVal, temp);
    }
    return minVal;
}


int main() {
    cout << Zeroes(10, 10) << endl;


}