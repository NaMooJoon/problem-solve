#include <bits/stdc++.h>
using namespace std;

#define MAX     100004

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    string s;
    string names[MAX];
    map<string, int> mp;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> names[i];
        mp[names[i]] = i + 1;
    }
    for (int i = 0; i < M; i++) {
        cin >> s;   
        if ('0' <= s[0] && s[0] <= '9') {
            cout << names[stoi(s) - 1] << '\n';
        } else {
            cout << mp[s] << '\n';
        }
    }

    return 0;   
}