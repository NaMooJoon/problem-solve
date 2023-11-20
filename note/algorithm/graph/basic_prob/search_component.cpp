#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int m, n, k, y, x, ret, ny, nx, t;
int a[104][104];
bool visited[104][104];

void dfs(int y, int x)
{
    visited[y][x] = 1;
}

int main (void)
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                ret++;
                dfs(i, j);
            }
        }
    }

    return 0;
}