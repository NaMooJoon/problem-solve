#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll memo[1000001] = {0};

ll solve(ll n, int p, int q)
{
    if (n == 0) {
        return 1;
    }
    if (n < 1000001) {
        if (memo[n] != 0) {
            return memo[n];
        }
        memo[n] = solve(n / p, p, q) + solve(n / q, p, q);
        return memo[n];
    }

    return solve(n / p, p, q) + solve(n / q, p, q);
}

int main (void)
{
    ll N;
    int P, Q;

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> P >> Q;

    cout << solve(N, P, Q) << '\n';

    return 0;
}