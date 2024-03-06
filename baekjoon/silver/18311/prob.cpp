#include <bits/stdc++.h>
using namespace std;
#define SIZE    100000

int N;
long long K;
long long total;
int arr[SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    total = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }
}

void solve() {
    int i = 0;
    int di = 1;
    if (total <= K) {
        K -= total;
        i = N - 1;
        di = -1;
    }

    while (i >= 0 && i < N) {
        K -= arr[i];
        if (K < 0) {
            break;
        }
        i += di;
    }
    cout << i + 1 << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}