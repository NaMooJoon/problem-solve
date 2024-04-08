#include <bits/stdc++.h>
using namespace std;
#define SIZE    100000

/**
 * Binary search로 정답 구하자.
 */
int N, M;
int total = 0;
int arr[SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }
}

bool check(int length) {
    int idx = 0;
    int total = 0, count = 0;
    while (idx < N) {
        total += arr[idx++];
        if (total > length) {
            count++;
            total = 0;
            idx--;
        }
        if (count >= M) { 
            return false; 
        }
    }
    return true;
}

void solve() {
    int answer = total;
    int l = 1, r = total, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            answer = min(answer, mid);
        } else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}