#include <bits/stdc++.h>
using namespace std;
#define SIZE    51

int N, L, R;
int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

/* function for debugging */
void errorPrint(const string s) {
    cout << "[ERROR] " << s << '\n';
}

/* functions for calculating possibility of move */
bool canMove(int from_y, int from_x, int to_y, int to_x) {
    int diff = abs(arr[from_y][from_x] - arr[to_y][to_x]);
    return (L <= diff && diff <= R);
}

bool isPossibleMoveInArr() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != N - 1 && canMove(i, j, i + 1, j)) {
                return true;
            }
            if (j != N - 1 && canMove(i, j, i, j + 1)) {
                return true;
            }
        }
    }
    return false;
}

void checkMovableScopeDFS(int y, int x, vector<pair<int,int>>& scope) {
    visited[y][x] = 1;
    scope.push_back({y, x});

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            continue;
        }
        if (visited[ny][nx] == 1) {
            continue;
        }
        if (!canMove(y, x, ny, nx)) {
            continue;
        }
        checkMovableScopeDFS(ny, nx, scope);
    }
}

/* functions for game */
void openTheGate(vector<pair<int,int>> scope) {
    int totalPopulation = 0;
    for (auto p : scope) {
        totalPopulation += arr[p.first][p.second];
    }
    
    int averagePopulation = totalPopulation / scope.size();
    for (auto p : scope) {
        arr[p.first][p.second] = averagePopulation;
    }
}


void passOneDay() {
    vector<vector<pair<int,int>>> v;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                vector<pair<int,int>> scope;
                checkMovableScopeDFS(i, j, scope);
                v.push_back(scope);
            }
        }
    }

    for (vector<pair<int,int>> scope : v) {
        openTheGate(scope);
    }
}

int calculateTakendays () {
    int ret = 0;
    while (isPossibleMoveInArr()) {
        passOneDay();
        ret++;
    }
    return ret;
}

int main (void)
{
    ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N >> L >> R;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cout << calculateTakendays() << '\n';

    return 0;
}