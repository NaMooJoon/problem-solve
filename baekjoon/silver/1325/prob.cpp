#include<bits/stdc++.h>
using namespace std;
#define SIZE    10001

vector<int> v[SIZE];
bool visited[SIZE];

int dfs(int idx) {
    visited[idx] = true;

    int count = 1;
    for (int next : v[idx]) {
        if (visited[next]) {
            continue;
        }
        count += dfs(next);
    }
    return count;
}

int main(void) {
    int N, M;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    int here, there;
    for (int i = 0; i < M; i++) {
        cin >> here >> there;
        v[there].push_back(here);
    }

    int max = 0;
    vector<int> v_max;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[SIZE], 0);
        int count = dfs(i);
        if (max < count) {
            max = count;
            v_max.clear();
            v_max.push_back(i);
        } else if (max == count) {
            v_max.push_back(i);
        }
    }

    sort(v_max.begin(), v_max.end());
    for (int i : v_max) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}