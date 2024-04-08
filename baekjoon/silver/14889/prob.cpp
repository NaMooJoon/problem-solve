#include <bits/stdc++.h>
using namespace std;
#define SIZE    32

int N;
int arr[SIZE][SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
}

bool isHalf(int mask) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (mask & 1) count++;
        mask = mask >> 1;
    }
    return (count == N / 2);
}

int calculateSumOf(int mask, bool teamNumber) {
    vector<int> v;
    for (int i = 0; i < N; i++) {
        if ((mask & 1) == teamNumber) {
            v.push_back(i);
        }
        mask = mask >> 1;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i != j) {
                int player1 = v[i];
                int player2 = v[j];
                sum += arr[player1][player2];
            }
        }
    }
    return sum;
}

void solve() {
    int min_diff = INT_MAX;
    int max_mask = 1 << N;
    for (int i = 0; i < max_mask; i++) {
        if (isHalf(i)) {
            int team0Sum = calculateSumOf(i, 0);
            int team1Sum = calculateSumOf(i, 1);
            int diff = (team0Sum - team1Sum > 0) ? 
                    team0Sum - team1Sum : team1Sum - team0Sum;
            min_diff = min(min_diff, diff);
        }
    }
    cout << min_diff << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}