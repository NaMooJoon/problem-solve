#include <bits/stdc++.h>
using namespace std;

inline int getSize(int level) {
    return 4 * level - 3;
}

inline string getFirstLine(int level) {
    string first = "";
    for (int i = 0; i < getSize(level); i++) {
        first.push_back('*');
    }
    return first;
}

inline string getSecondLine(int level) {
    string second = "";
    second.push_back('*');
    for (int i = 0; i < getSize(level) - 2; i++) {
        second.push_back(' ');
    }
    second.push_back('*');
    return second;
}

string solve(int level, string s) {
    const string PREFIX = "* ";
    const string POSTFIX = " *";
    
    string ret = "";

    string firstOutline = getFirstLine(level);
    string secondOutLine = getSecondLine(level);
    
    ret += firstOutline;
    ret += secondOutLine;

    int beginIdx = 0, len = getSize(level - 1);
    for (int i = 0; i < getSize(level - 1); i++) {
        ret += PREFIX;
        ret += s.substr(beginIdx, len);
        ret += POSTFIX;

        beginIdx += len;
    }

    ret += secondOutLine;
    ret += firstOutline;
    return ret;
}

void printResult(int level, string s) {
    int idx = 0;
    for (int i = 0; i < getSize(level); i++) {
        for (int j = 0; j < getSize(level); j++) {
            cout << s[idx++];
        }
        cout << '\n';
    }
}

int main(void) {
    int N;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    string s = "*";

    for (int level = 2; level <= N; level++) {
        s = solve(level, s);
    }
    printResult(N, s);
    return 0;
}