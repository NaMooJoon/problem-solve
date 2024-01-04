/* 1,2,3 더하기 4 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE       3

void inputInit(int& T) {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
}

int solve(int n) {

    int ret = 0;
    int dp[SIZE + 1][n + 1];

    // only 1
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
    
    // 1 and 2
    dp[2][0] = dp[2][1] = 0;
    dp[2][2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[2][i] = dp[1][i - 2] + dp[2][i - 2];
    }
    
    // 1 and 2 and 3
    dp[3][0] = dp[3][1] = dp[3][2] = 0;
    dp[3][3] = 1;
    for (int i = 4; i <= n; i++) {
        dp[3][i] = dp[1][i - 3] + dp[2][i - 3] + dp[3][i - 3];
    }

    for (int num = 1; num <= 3; num++) {
        ret += dp[num][n];
    }
    return ret;
}

int main (void) {

    int T, n;

    inputInit(T);

    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}