#include <bits/stdc++.h>
using namespace std;
#define SIZE    1001

int height, width;
int arr[SIZE][SIZE];
bool visitedFire[SIZE][SIZE];
int visited[SIZE][SIZE];

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

void fireOneStep(queue<pair<int,int>>& fireTogo) {
    if (fireTogo.empty()) {
        return ;
    }

    int y = fireTogo.front().first;
    int x = fireTogo.front().second;
    fireTogo.pop();

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
            continue;
        }
        if (visitedFire[ny][nx] == 1) {
            continue;
        }
        if (arr[ny][nx] == 0) {
            continue;
        }
        visitedFire[ny][nx] = 1;
        fireTogo.push({ny, nx});
    }
}

int JihunOutTime(queue<pair<int,int>>& togo) {
    int y = togo.front().first;
    int x = togo.front().second;
    togo.pop();

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
            return visited[y][x];
        }
        if (visited[ny][nx] != 0) {
            continue;
        }
        if (visitedFire[ny][nx] == 1) {
            continue;
        }
        if (arr[ny][nx] == 0) {
            continue;
        }
        visited[ny][nx] = visited[y][x] + 1;
        togo.push({ny, nx});
    }
    return -1;
}

int calculateTakenTime() {
    // BFS
    queue<pair<int,int>> togo;
    queue<pair<int,int>> fireTogo;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (arr[i][j] == 2) {
                togo.push({i, j});
                visited[i][j] = 1;
            }
            if (arr[i][j] == -1) {
                fireTogo.push({i, j});
                visitedFire[i][j] = 1;
            }
        }
    }

    while (true) {
        int fireCount = fireTogo.size();
        for (int i = 0; i < fireCount; i++) {
            fireOneStep(fireTogo);
        }
        int togoCount = togo.size();
        for (int i = 0; i < togoCount; i++) {
            int outTime = JihunOutTime(togo);
            if (outTime != -1) {
                return outTime;
            }
        }
       
        if (togo.empty()) {
            return -1;
        }
    }
    return -1;
}

int main (void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;

    cin >> height >> width;
    for (int i = 0; i < height; i++) {
        cin >> s;
        for (int j = 0; j < width; j++) {
            if (s[j] == '.') {
                arr[i][j] = 1;
            }
            else if (s[j] == 'J') {
                arr[i][j] = 2;
            }
            else if (s[j] == 'F') {
                arr[i][j] = -1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }

    int time = calculateTakenTime();
    if (time == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    cout << time << '\n';

    return 0;
}