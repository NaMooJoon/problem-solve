#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, answer = "";

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;

    if (s == "0") {
        cout << 0 << '\n';
        return 0;
    }

    queue<char> q;

    for (int i = 0; i < s.length(); i++) {
        int num = s[i] - '0';

        if (num >= 4) {
            q.push('1');
            num -= 4;
        } else {
            q.push('0');
        }

        if (num >= 2) {
            q.push('1');
            num -= 2;
        } else {
            q.push('0');
        }

        if (num >= 1) {
            q.push('1');
            num -= 1;
        } else {
            q.push('0');
        }
    }

    while (q.front() == '0') {
        q.pop();
    }

    while (q.size()) {
        cout << q.front();
        q.pop();
    }
    cout << '\n';
}