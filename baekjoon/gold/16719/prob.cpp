#include <bits/stdc++.h>
using namespace std;
#define SIZE    100

/**
 * 
 */
string zoak;
bool visited[SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> zoak;
}

string ZOAK(string prefix, string postfix, int start, int end) {
    if (start >= end) {
        return prefix + postfix;
    }

    int min_idx = start;
    for (int i = start + 1; i < end; i++) {
        if (visited[i] == 0 && zoak[min_idx] > zoak[i]) {
            min_idx = i;
        }
    }
    visited[min_idx] = 1;
    string word = prefix + zoak[min_idx];
    cout << prefix + zoak[min_idx] + postfix << '\n';

    word = ZOAK(word, postfix, min_idx + 1, end);
    word = word.substr(prefix.length(), word.length() - prefix.length());
    word = ZOAK(prefix, word, start, min_idx);
    return word;
}

void solve() {
    memset(visited, 0, sizeof(visited));
    ZOAK("", "", 0, zoak.length());
}

int main(void) {
    inputInit(); 
    solve();
    return 0;
}