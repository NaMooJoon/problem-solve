#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int stone_N, bag_N;
vector<pair<ll,ll>> stone;
vector<ll> bag;

void inputInit() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> stone_N >> bag_N;
    ll weight, value;
    for (int i = 0; i < stone_N; i++) {
        cin >> weight >> value;
        stone.push_back({weight, value});
    }
    for (int i = 0; i < bag_N; i++) {
        cin >> weight;
        bag.push_back(weight);
    }
    sort(stone.begin(), stone.end());
    sort(bag.begin(), bag.end());
}

ll solve() {
    ll total = 0;

    int idx = 0;
    priority_queue<ll> pq;
    for (int bag_weight : bag) {
        while (idx < stone_N && stone[idx].first <= bag_weight) {
            pq.push(stone[idx++].second);
        }
        if (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
    }

    return total;
}

int main(void) {

    inputInit();

    ll answer = solve();
    cout << answer << '\n';
    return 0;
}