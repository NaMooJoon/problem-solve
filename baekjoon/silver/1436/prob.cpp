#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int num = 660;
    while (n > 0) {
        num++;
        if (to_string(num).find("666") != string::npos) {
            n--;
        }
    }
    return num;
}

int main(void)
{
    int n;
    cin >> n;
    cout << solve(n) << '\n';
    return 0;
}