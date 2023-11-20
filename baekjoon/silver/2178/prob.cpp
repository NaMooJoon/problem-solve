#include <bits/stdc++.h>
#define SIZE        100
using namespace std;

int arr[SIZE][SIZE];
int visited[SIZE][SIZE];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M;


void bfs (int y, int x)
{
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                continue;
            }
            if (arr[ny][nx] == 0) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main (void)
{
    string s;
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = (int) (s[j] - '0');
        }
    }
    bfs(0, 0);
    cout << visited[N - 1][M - 1] << '\n';

    return 0;
}