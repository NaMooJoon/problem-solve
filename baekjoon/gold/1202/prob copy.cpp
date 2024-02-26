#include <bits/stdc++.h>
using namespace std;

int stone_N, bag_N;
vector<pair<int,int>> stone;
vector<int> bag;

void inputInit() { 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> stone_N >> bag_N;
    int weight, value;
    for (int i = 0; i < stone_N; i++) {
        cin >> weight >> value;
        stone.push_back({value, weight});
    }
    sort(stone.begin(), stone.end(), greater<>());
    for (int i = 0; i < bag_N; i++) {
        cin >> weight;
        bag.push_back(weight);
    }
    sort(bag.begin(), bag.end());
}

int solve() {
    int total = 0;
    bool visited[stone.size()];
    memset(visited, 0, sizeof(visited));
    for (int newBag : bag) {
        int idx = 0;
        for (pair<int,int> newStone : stone) {
            if (visited[idx] == 1) {
                idx++;
                continue;
            }

            int stone_value = newStone.first;
            int stone_weight = newStone.second;
            if (newBag >= stone_weight) {
                total += stone_value;
                visited[idx] = 1;
                break;
            }
            idx = idx + 1;
        }
    }
    return total;
}

int main(void) {

    inputInit();

    int answer = solve();
    cout << answer << '\n';
    return 0;
}