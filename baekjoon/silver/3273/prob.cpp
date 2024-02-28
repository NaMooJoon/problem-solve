#include <bits/stdc++.h>
using namespace std;
#define SIZE 100001

int arr[SIZE];
int N, sum;

void inputInit() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> sum;

    sort(arr, arr + N);
}

void solve() {
    int count = 0;

    int i = 0, j = N - 1;
    while (i < j) {
        if (arr[i] + arr[j] == sum) {
            count++;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] < sum) {
            i++;
        }
        else if (arr[i] + arr[j] > sum) {
            j--;
        }
    }

    cout << count << '\n';
}

int main(void) {
    inputInit();
    solve();

    return 0;
}