#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE    11

int N;
int population[MAX_SIZE];
vector<int> graph[MAX_SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int count;
    for (int i = 0; i < N; i++) {
        cin >> count;
        population[i + 1] = count;
    }
    
    int adj;
    for (int i = 0; i < N; i++) {
        cin >> count;
        for (int j = 0; j < count; j++) {
            cin >> adj;
            graph[i + 1].push_back(adj);
        }
    }
}

bool isArea(int pos, vector<int>& area) {
    for (int p : area) {
        if (p == pos) {
            return true;
        }
    }
    return false;
}

void dfs(int from, bool visited[], vector<int>& area) {
    visited[from] = 1;
    for (int to : graph[from]) {
        if (visited[to] == 0 && isArea(to, area)) {
            dfs(to, visited, area);
        }
    }
}

int solve() {
    int _min = INT_MAX;
    
    for (int bit_mask = 1; bit_mask < (1 << N); bit_mask++) {
    
        bool flag = true;
        vector<int> area0, area1;
        bool visited[N + 1];
        memset(visited, 0, N + 1);
        queue<int> q;

        // split area
        for (int i = 0; i < N; i++) {
            if (bit_mask & (1 << i)) {
                area1.push_back(i + 1);
            } else {
                area0.push_back(i + 1);
            }
        }
        // check if possible
        if (area0.empty() || area1.empty()) {
            continue;
        }
        // check area0
        int first_checking_num = area0.back(); 
        dfs(first_checking_num, visited, area0);
        for (int pos : area0) {
            if (visited[pos] == 0) {
                flag = false;
                break;
            }
        }
        // check area1
        first_checking_num = area1.back(); 
        dfs(first_checking_num, visited, area1);
        for (int pos : area1) {
            if (visited[pos] == 0) {
                flag = false;
                break;
            }
        }

        // for debug
        if (flag) {
            int population0 = 0;
            for (int i : area0) {
                population0 += population[i];
            }
            int population1 = 0;
            for (int i : area1) {
                population1 += population[i];
            }
            _min = min(_min, abs(population0 - population1));
        }
    }

    return (_min == INT_MAX)? -1 : _min;
}

int main(void) {
    inputInit();
    cout << solve() << '\n';

    return 0;
}