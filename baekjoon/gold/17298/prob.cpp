#include <bits/stdc++.h>
using namespace std;
#define SIZE    1000000

int arr[SIZE];
int nge[SIZE];
int idx[SIZE];

int main (void) {
    int N;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    nge[N - 1] = -1;
    idx[N - 1] = N;
    int i, j;
    for (i = N - 2; i >= 0; i--) {
        for (j = i + 1; j < N; j++) {
            if (arr[i] < arr[j]) {
                nge[i] = arr[j];
                idx[i] = j;
                break;
            } else if (arr[i] < nge[j]) {
                nge[i] = nge[j];
                idx[i] = idx[j];
                break;
            }
            j = idx[j];
        }
        if (j >= N) {
            nge[i] = -1;
            idx[i] = N;
        }
    }

    for (i = 0; i < N; i++) {
        cout << nge[i] << ' ';
    }
    cout << '\n';

    return 0;
}