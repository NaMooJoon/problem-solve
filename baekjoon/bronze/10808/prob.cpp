#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int numOfChar['z' + 1] = {0};
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        ++numOfChar[(int) s[i]];
    }
    for (int i = 'a'; i <= 'z'; i++) {
        cout << numOfChar[i] << ' ';
    }
    cout << '\n';

    return 0;
}