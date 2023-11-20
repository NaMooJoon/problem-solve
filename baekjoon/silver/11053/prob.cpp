#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN     1000

int main (void)
{
    int N;
    int max = 1, newLen;
    int arr[MAX_LEN];
    int dp[MAX_LEN] = {0};
    bool flag;

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        flag = true;
        for (int j = i - 1; j >= 0; j--) {
            newLen = dp[j] + 1;
            if (arr[j] < arr[i] && dp[i] < newLen) {
                dp[i] = newLen;
                flag = false;
            }
        }
        if (flag) {
            dp[i] = 1;
        }
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    cout << max << '\n';

    return 0;  
}


