#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main (void)
{
    LL N;
    LL total = 0;

    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i < N; i++) {
        total += (N * i) + i;
    }

    cout << total << '\n';
    

    return 0;
}