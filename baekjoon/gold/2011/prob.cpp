#include <bits/stdc++.h>
using namespace std;

#define MOD     1000000
#define SIZE    5000

inline bool isOneDigit (string s, int idx)
{
    return (s[idx] == '0')? false : true;
}

inline bool isTwoDigits (string s, int idx)
{
    int num;
    if (s[idx - 1] == '0') {
        return false;
    }
    num = (s[idx - 1] - '0') * 10 + (s[idx] - '0');
    if (10 <= num && num <= 26) {
        return true;
    }
    return false;
}

int main (void)
{
    int len;
    string s;
    int dp[SIZE + 1];
    bool isOne, isTwo;

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> s;

    if (s[0] == '0') {
        cout << "0" << '\n';
        exit(0);
    }

    len = s.size();

    dp[0] = 1;
    dp[1] = (isOneDigit(s, 1))?     1 : 0;
    dp[1] += (isTwoDigits(s, 1))?   1 : 0;
    for (int i = 2; i < len; i++) {
        isOne = isOneDigit(s, i);
        isTwo = isTwoDigits(s, i);

        dp[i] =     (isOne)? dp[i - 1] : 0;
        dp[i] +=    (isTwo)? dp[i - 2] : 0;
        dp[i] %=    MOD;

        if (!(isOne | isTwo)) {
            cout << "0" << '\n';
            exit(0);
        }
    }

    cout << dp[len - 1] << '\n';


    return 0;
}