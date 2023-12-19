#include <bits/stdc++.h>
using namespace std;
#define MOD     1000000007
// #define MOD    13 

long long power(int a, int n) {
    if (n == 0) {
        return 1;
    }
    long long half = power(a, n / 2);
    if (n & 1) {
        return ((half * half) % MOD) * a % MOD;
    }
    return (half * half) % MOD;
}

long long biCoeffi(int n, int k) {
    if (k > n - k) {
        k = n - k;
    }
    
    long long numerator = 1;
    long long denominator = 1;
    for (int i = n; i >= n - k + 1; i--) {
        numerator = (numerator * i) % MOD;
    }
    for (int i = k; i >= 1; i--) {
        denominator = (denominator * i) % MOD;
    }
    return ((numerator % MOD) * power(denominator, MOD-2)) % MOD;
}

int main (void) {
    int n, k;

    cin >> n >> k;
    cout << biCoeffi(n, k) << '\n';

    return 0;
}