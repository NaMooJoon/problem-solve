#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    string s, c;
    cin >> s;

    c = s;
    reverse(c.begin(), c.end());
    cout << (s == c) << '\n';

    return 0;
}