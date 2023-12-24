#include <bits/stdc++.h>
using namespace std;
#define SIZE    2048
#define TRUE    1
#define FALSE   0

int memo[SIZE * 2];
int arr[SIZE];

int isPalindrom(int start, int end) {

    int len = (end - start) + 1;

    int needTocheckSize = max(0, len - memo[start + end]) / 2;
    for (int i = 0; i < needTocheckSize; i++) {
        if (arr[start + i] != arr[end - i]) {
            return FALSE;
        }
    }
    memo[start + end] = max(len, memo[start + end]);
    return TRUE;
}

int main(void) {

    int N, M;
    int start, end;

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> M;
    for (int question = 0; question < M; question++) {
        cin >> start >> end;
        start--; end--;

        cout << isPalindrom(start, end) << '\n';
    }


    return 0;   
}