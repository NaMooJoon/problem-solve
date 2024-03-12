#include <bits/stdc++.h>
using namespace std;

int len;
string full;
string fire;
deque<char> dq;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> full;
    cin >> fire;
    len = fire.length();
}

void solve() {
    
    int idx = 0;
    int level = 0;
    for (char ch : full) {
        if (ch != fire[idx] && ch != fire[0]) {
            dq.push_back(ch);
            idx = 0;
            level = 0;
        }
        else if (ch == fire[idx]) {
            dq.push_back(-1 * idx);
            idx++;
            if (idx == len) {
                for (int i = 0; i < len; i++) {
                    dq.pop_back();
                }
                if (level > 0) {
                    idx = -1 * dq.back() + 1;
                    level--;
                } else {
                    idx = 0;
                }
            }
        }
        else if (idx != 0 && ch == fire[0]) {
            dq.push_back(0);
            idx = 1;
            level++;
        }
    }
}

void printResult() {

    if (dq.empty()) {
        cout << "FRULA" << '\n';
    } 
    else {
        while (dq.size()) {
            char ch = dq.front();
            if (ch <= 0) {
                cout << fire[ch * -1];
            } else {
                cout << ch;
            }
            dq.pop_front();
        }
        cout << '\n';
    }
}

int main(void) {
    inputInit();
    solve();
    printResult();

    return 0;
}