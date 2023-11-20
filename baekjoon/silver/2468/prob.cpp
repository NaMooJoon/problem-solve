#include <bits/stdc++.h>
#define SIZE        100
using namespace std;

int N;
int arr[SIZE][SIZE];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int safe[][SIZE], bool visited[][SIZE], int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            continue;
        }
        if (safe[ny][nx] == 0 || visited[ny][nx] == 1) {
            continue;
        }
        dfs(safe, visited, ny, nx);
    }
}

int solve (int min) 
{   
    int ret = 0;
    int safe[SIZE][SIZE];
    bool visited[SIZE][SIZE];

    fill(&safe[0][0], &safe[0][0] + (SIZE * SIZE), 0);
    fill(&visited[0][0], &visited[0][0] + (SIZE * SIZE), 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > min) {
                safe[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0 && safe[i][j] == 1) {
                dfs(safe, visited, i, j);
                ret++;
            }
        }
    }
    return ret;
}

int main (void)
{
    int max = 1;
    map<int,int> mp;

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            mp[arr[i][j]]++;
        }
    }
    for (int i = 0; i < mp.size(); i++) {
        if (mp[i]) {
            int tmp = solve(i);
            if (max < tmp) {
                max = tmp;
            }
        }
    }
    cout << max << '\n';


    return 0;
}