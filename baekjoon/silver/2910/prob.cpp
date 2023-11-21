/* 빈도 정렬 */
#include <bits/stdc++.h>
using namespace std;

map<int,int> mp_first;

bool comp(pair<int,int> case1, pair<int,int> case2)
{
    if (case1.second == case2.second) {
        return mp_first[case1.first] < mp_first[case2.first];
    }
    return case1.second > case2.second;
}

int main (void)
{
    int N, C, ch;
    map<int,int> mp;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> ch;
        mp[ch]++;
        if (mp_first[ch] == 0) {
            mp_first[ch] = i + 1;
        }
    }

    vector<pair<int,int>> v;
    for (auto& it : mp) {
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), comp);

    for (auto& it : v) {
        for (int i = 0; i < it.second; i++) {
            cout << it.first << ' ';
        }
    }
    cout << '\n';

    return 0;
}