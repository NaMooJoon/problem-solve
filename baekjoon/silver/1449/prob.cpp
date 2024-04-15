#include <bits/stdc++.h>
using namespace std;
#define SIZE    1024

int N, L;
int arr[SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    sort(arr, arr + N);

    int endOfTape, count = 0;;
    bool isPasting = true;
    for (int i = 0; i < N; i++) {
        if (isPasting) {
            endOfTape = arr[i] + L - 1; // -1 : 0.5 + 0.5
            count = count + 1;
            isPasting = false;
            continue;
        }
        if (arr[i] <= endOfTape) {
            continue;
        }
        isPasting = true;
        i--;
    }
    cout << count << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}