#include <bits/stdc++.h>
using namespace std;
#define SIZE    300000

int N, M;
int arr[SIZE];
int lo = 1, hi = 0, mid;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M; 
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        hi = max(arr[i], hi);
    }
}

bool check(int max) {
    int numOfStudent = 0;
    for (int i = 0; i < M; i++) {
        numOfStudent += arr[i] / max;
        if (arr[i] % max) numOfStudent++;
    }
    return (numOfStudent <= N);
}

void solve() {
    int ret = hi;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
            ret = min(ret, mid);
            continue;
        }
        lo = mid + 1;
    }
    cout << ret << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}