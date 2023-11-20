#include <bits/stdc++.h>
using namespace std;

#define MOD         1000000
#define SIZE        4

int memo[10000] = {0};

int codeToNum (vector<char> v)
{
    int num;
    int ret = 0;
    for (char ch : v) {
        num = ch - 'A' + 1;
        ret = (num >= 10)? (ret * 100) + num : (ret * 10) + num;
    }
    return ret;
}

void printV(vector<char> v) 
{
    for (char ch : v) {
        cout << ch;
    }
    cout << '\n';
}

int solve (string s, vector<char> v) 
{
    char ch;
    int pos, len = s.size();
    int ret1 = 0, ret2 = 0;

    if (s[0] == '0') {
        return 0;
    }
    if (len == 0) {
        printV(v);
        return 1;
    }

    ch = (s[0] - '1') + 'A';
    if (len == 1) {
        v.push_back(ch);
        printV(v);
        return 1;
    }

    for (int i = 0; i < len; i++) {
        if (s[i] > '2') {
            pos = i + 1;
        }
    }

    /* calculate */
    v.push_back(ch);
    ret1 = solve(s.substr(1, len), v);
    v.pop_back();

    ch = ((s[0] - '0') * 10) + (s[1] - '1') + 'A';
    if ('A' <= ch && ch <= 'Z') {
        v.push_back(ch);
        ret2 = solve(s.substr(2, len), v);
        v.pop_back();
    }

    return ret1 + ret2;
}

int main (void)
{
    string s;
    vector<char> v;

    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;

    cout << solve(s, v) << '\n';

    return 0;
}