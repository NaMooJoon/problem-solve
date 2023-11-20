#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int n, m, answer;
    string name, kind;
    map<string, int> mp;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        mp.clear();
        answer = 1;
        for (int j = 0; j < m; j++) {
            cin >> name >> kind;
            mp[kind]++;
        }
        for (auto it : mp) {
            answer *= (it.second + 1);
        }
        cout << answer - 1 << '\n';
    }

    return 0;
}