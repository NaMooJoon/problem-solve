#include <bits/stdc++.h>
using namespace std;
#define SIZE    4000001

int N;
bool arr[SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    memset(arr, 1, sizeof(arr));
    arr[0] = arr[1] = 0;
    for (int num = 2; num <= N; num++) {
        if (arr[num]) {
            for (int i = 2 * num; i <= N; i += num) { 
                // 배수들
                arr[i] = 0;
            }
        }
    }
}

int getNextPrimeIdx(int idx) {
    for (int i = idx + 1; i <= N; i++) {
        if (arr[i]) {
            return i;
        }
    }
    return -1;
}

int getSumOfSequencePrime(int from, int to) {
    int total = 0;
    for (int i = from; i <= to; i++) {
        if (arr[i]) {
            total += i;
        }
    }
    return total;
}

void solve() {
    int count = 0;
    int startIdx = 2;
    int endIdx = 2;
    while (true) {
        if (startIdx == -1 || endIdx == -1) break;
        if (startIdx > endIdx) break;
        int total = getSumOfSequencePrime(startIdx, endIdx);
        if (total == N) {
            count++;
            startIdx = getNextPrimeIdx(startIdx);
        }
        if (total < N) {
            endIdx = getNextPrimeIdx(endIdx);
        }
        if (total > N) {
            startIdx = getNextPrimeIdx(startIdx);
        }
    }
    cout << count << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}