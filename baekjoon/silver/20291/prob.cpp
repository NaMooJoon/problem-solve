#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    map<string, int> mp;
    string filename, ext;
    while (N--) {
        cin >> filename;
        string::size_type pos = filename.find('.') + 1;
        ext = filename.substr(pos);
        mp[ext]++;
    }
    for (auto& a : mp) {
        cout << a.first << ' ' << a.second << '\n';
    }
    return 0;
}