#include <bits/stdc++.h>
using namespace std;

long long solve (long long a, long long b, long long c)
{
    long long ret;
    if (b == 1) {
        return (a % c);
    }
    ret = solve(a, b / 2, c);
    ret = (ret * ret) % c;
    if (b & 1) {
        ret = (ret * a) % c;
    }
    return ret;
}

int main (void)
{
    long long a, b, c;

    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    
    cout << solve(a, b, c) << '\n';

    return 0;
}
