#include <bits/stdc++.h>
#define SIZE        50
using namespace std;

int M, N;
int mp[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs (int y, int x) 
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
            continue;
        }
        if (visited[ny][nx]) {
            continue;
        }
        if (mp[ny][nx] == 0) {
            continue;
        }
        dfs(ny, nx);
    }
}

int main (void)
{
    int count;
    int y, x;
    int T, K;
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--) 
    {
        count = 0;
        fill(mp[0], mp[0] + (SIZE * SIZE), 0);
        fill(visited[0], visited[0] + (SIZE * SIZE), 0);
        
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            mp[y][x] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 0 && mp[i][j] == 1) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}