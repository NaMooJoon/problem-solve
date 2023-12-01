/* 2636번, 치즈 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE    101

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int height, width;
int board[SIZE][SIZE];

/**
 * @brief 
 * 흰색을 통해서 DFS로 범위를 탐색.
 * 흰색이 구멍이라면 pass,
 * 흰색 범위 끝에서 1을 만난 경우, 해당 1은 0으로, 그리고 visited = 1;
 */
void readBoard() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> board[i][j];
        }
    }
}

int getRestCheeseNumber() {
    int ret = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 1) ret++;
        }
    }
    return ret;
}

bool hole_dfs(int y, int x, bool (*hole_visited)[SIZE]) {
    hole_visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= height || nx < 0 || nx >= width) { // not hole
            return false;
        }
        if (hole_visited[ny][nx]) {
            continue;
        }
        if (board[ny][nx] == 1) {
            continue;
        }
        return hole_dfs(ny, nx, hole_visited);
    }
    return true;
}

bool isHole(int i, int j) {
    bool hole_visited[SIZE][SIZE]; 
    memset(hole_visited, 0, sizeof(hole_visited));
    return hole_dfs(i, j, hole_visited);
}

void melt_dfs(int y, int x, bool (*visited)[SIZE], vector<pair<int,int>>& v) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
            continue;
        }
        if (visited[ny][nx]) {
            continue;
        }
        if (board[ny][nx] == 1) {
            v.push_back({ny, nx});
            continue;
        }
        melt_dfs(ny, nx, visited, v);
    }
}

void melt(vector<pair<int,int>> v) {
    for (auto& it : v) {
        board[it.first][it.second] = 0;
    }
}

void meltingCheese() {
    bool visited[SIZE][SIZE];
    vector<pair<int,int>> v;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (visited[i][j]) { continue; }
            if (board[i][j] == 1) { continue; }
            if (isHole(i, j)) { continue; }
            melt_dfs(i, j, visited, v);
        }
    }
    if (v.size() == 0 && getRestCheeseNumber() != 0) {
        for (int i = 0; i < height; i++) {
            v.push_back({i, 0});
            v.push_back({i, width - 1});
        }
        for (int j = 0; j < height; j++) {
            v.push_back({0, j});
            v.push_back({height - 1, 0});
        }
    }
    melt(v);
}

int main (void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> height >> width;
    readBoard();

    int prev = getRestCheeseNumber(), curr;
    
    int time = 0;
    while ((curr = getRestCheeseNumber()) != 0) {
        time++;
        meltingCheese();
        prev = curr;
    }

    cout << time << '\n' << prev << '\n';

    return 0;
}
