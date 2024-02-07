#include <bits/stdc++.h>
using namespace std;
#define SIZE        1000

int N, M, V;
bool graph[SIZE + 1][SIZE + 1];
bool visited[SIZE + 1];

void inputInit() {
    int u, v;
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void visitedInit() {
    memset(visited, 0, SIZE + 1);
}

void _dfs(int from) {
    visited[from] = 1;
    cout << from << ' ';
    for (int to = 0; to < SIZE + 1; to++) {
        if (graph[from][to] == 1 && visited[to] == 0) {
            _dfs(to);
        }
    }
}

void DFS() {
    _dfs(V);
    cout << '\n';
}

void _bfs(int start) {
    queue<int> q;
    q.push(start);

    while (q.size() > 0) {
        int from = q.front(); q.pop();
        if (visited[from] == 1) {
            continue;
        }
        visited[from] = 1;
        cout << from << ' ';
        for (int to = 0; to < SIZE + 1; to++) {
            if (graph[from][to] == 1 && visited[to] == 0) {
                q.push(to);
            }
        }
    }
}

void BFS() {
    _bfs(V);
    cout << '\n';
}

int main(void) {
    inputInit();

    visitedInit();
    DFS();

    visitedInit();
    BFS();

    return 0;
}