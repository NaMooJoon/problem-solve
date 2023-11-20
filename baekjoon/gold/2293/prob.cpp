#include <bits/stdc++.h>
using namespace std;

#define MAX_VAL     100000

int main (void)
{
    int val;
    int n, k;
    int dp[MAX_VAL + 1] = {0};
    vector<int> coin;

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> val;
        coin.push_back(val);
    }

    fill_n(dp, k + 1, 0);
    dp[0] = 1;
    
    for (int n : coin) {
        for (int i = 1; i <= k; i++) {
            if ((i - n) >= 0) {
                dp[i] = dp[i - n] + dp[i];
            }
        }
    }

    cout << dp[k] << '\n';

    return 0;
}