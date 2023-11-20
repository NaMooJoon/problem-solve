#include <bits/stdc++.h>
#define SIZE        1000
using namespace std;


int main (void)
{
    int N, len;
    int arr[SIZE];
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> len;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        if (len < arr[i]) {
            break;
        }
        len++;
    }
    cout << len << '\n';
    return 0;
}