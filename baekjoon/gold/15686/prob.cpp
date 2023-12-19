#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
int answer = __INT_MAX__;

int calculateDistance(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int findChickenDistance(vector<pair<int,int>> candidate, int count) {
    int total = 0;
    for (auto& p1 : house) {
        int _min = __INT_MAX__;
        for (int i = 0; i < count; i++) {
            auto& p2 = candidate[i];

            int newDist = calculateDistance(p1, p2);
            _min = min(newDist, _min);
        }
        total += _min;
    }
    return total;
}

void solve(vector<pair<int,int>> candidate, int start, int max) {
    if (candidate.size() == max) {
        int newDist = findChickenDistance(candidate, max);
        answer = min(newDist, answer);
        return;
    }
    for (int i = start + 1; i < chicken.size(); i++) {
        candidate.push_back(chicken[i]);
        solve(candidate, i, max);
        candidate.pop_back();
    }
}

int main (void)
{
    int N, M;   
    vector<pair<int,int>> candidate;
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    int space;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space;
            if (space == 1) {
                house.push_back({i, j});
            } 
            else if (space == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    solve(candidate, -1, M);
    cout << answer << '\n';

    return 0;
}