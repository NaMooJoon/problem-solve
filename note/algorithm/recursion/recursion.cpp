#include <bits/stdc++.h>

using namespace std;

int fact(int n) 
{
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}

int fact_for(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int fibo(int n) 
{
    if (n == 0 || n == 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

int n = 5;
int main (void)
{
    cout << fact(n) << " " << fibo(n) << '\n';
    return 0;
}