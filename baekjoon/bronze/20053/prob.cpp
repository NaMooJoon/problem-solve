#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, T;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        int _max = -1000000, _min = 1000000, num;
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> num;
            _max = max(_max, num);
            _min = min(_min, num);
        }
        cout << _min << ' ' << _max << '\n';
    }

    return 0;
}