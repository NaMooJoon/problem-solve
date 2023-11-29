#include <bits/stdc++.h>
using namespace std;

int count_factorial_zero (int n) 
{
    int two_count = 0;
    int five_count = 0;

    for (int i = 2; i <= n; i *= 2) {
        two_count += n / i;
    }
    for (int i = 5; i <= n; i *= 5) {
        five_count += n / i;
    }
    return min(two_count, five_count);
}

int main(void)
{
    int T, n;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << count_factorial_zero(n) << '\n';
    }
    return 0;
}