#include <bits/stdc++.h>
using namespace std;
#define SIZE    51

int height, width;
int mp[SIZE][SIZE];
int visited[SIZE][SIZE];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int calcShortestDistFrom(int y, int x) {
    queue<pair<int,int>> q;
    int max_visit = 1;
    visited[y][x] = 1;
    q.push({y, x});
    while (q.size()) {
        int here_y = q.front().first;
        int here_x = q.front().second;
        // cout << "here : " << here_y << ',' << here_x << '\n';
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = here_y + dy[i];
            int nx = here_x + dx[i];

            if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            if (mp[ny][nx] == 0) {
                continue;
            }
            visited[ny][nx] = visited[here_y][here_x] + 1;
            max_visit = max(max_visit, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
    return max_visit;
}

int solve() {
    int _max = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (mp[i][j] == 1) {
                fill(&visited[0][0], &visited[SIZE - 1][SIZE], 0);
                _max = max(_max, calcShortestDistFrom(i, j) - 1);
            }
        }
    }
    return _max;
}

int main(void)
{
    string s;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> height >> width;
    for (int i = 0; i < height; i++) {
        cin >> s;
        for (int j = 0; j < width; j++) {
            if (s[j] == 'W') {
                mp[i][j] = 0;
            } else {
                mp[i][j] = 1;
            }
        }
    }

    cout << solve() << '\n'; 

    return 0;
}