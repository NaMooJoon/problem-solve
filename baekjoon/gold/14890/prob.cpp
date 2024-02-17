#include <bits/stdc++.h>
using namespace std;
#define SIZE    101

int N, L;
int arr1[SIZE][SIZE], arr2[SIZE][SIZE];
int answer = 0;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr1[i][j];
            arr2[j][i] = arr1[i][j];
        }
    }
}

void solve(int arr[SIZE][SIZE]) {
    for (int i = 0; i < N; i++) {
        int len = 1;
        bool flag = true;
        for (int j = 0; j < N - 1; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                len++;
                continue;
            }
            if (arr[i][j] + 1 == arr[i][j + 1]) {
                if (len < L) {
                    flag = false;
                    break;
                }
                len = 1;
                continue;
            }
            if (arr[i][j] - 1 == arr[i][j + 1]) {
                if (len < 0) {
                    flag = false;
                    break;
                }
                len = 1 - L;
                continue;
            }
            flag = false;
            break;
        }

        if (len >= 0 && flag) {
            answer++;
        }
    }
}
int main(void) {
    inputInit();
    solve(arr1);
    solve(arr2);
    cout << answer << '\n';
    return 0;
}