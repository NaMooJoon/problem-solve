#include <bits/stdc++.h>
#define SIZE    100
using namespace std;

int mp[SIZE][SIZE];

int main(void)
{
    int H, W;
    string s;

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        cin >> s;
        for (int j = 0; j < W; j++) {
            if (s[j] == 'c') {
                mp[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 1; j < W; j++) {
            int prev = mp[i][j - 1];
            int next = mp[i][j];
            if (prev != 0 && next == 0) {
                mp[i][j] = prev + 1;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << mp[i][j] - 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}