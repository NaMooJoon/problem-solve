#include <bits/stdc++.h>
using namespace std;
#define SIZE    30

int main(void) {
    bool arr[SIZE];
    int num;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < SIZE - 2; i++) {
        cin >> num;
        arr[num - 1] = true;
    }

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == false) {
            cout << i + 1 << '\n';
        }
    }

    return 0;
}