#include <bits/stdc++.h>
using namespace std;
#define SIZE        500
#define WALL        2
#define WATER       1
#define EMPTY       0

int H, W;
int max_height = 0;
int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];

void printArr() {
    cout << '\n';
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    int height;
    for (int j = 0; j < W; j++) {
        cin >> height;
        max_height = max(max_height, height);
        for (int i = H - 1; i >= H - height; i--) {
            arr[i][j] = WALL;
        }
    }
}

bool check(int y, int x, int& start, int& end) {
    bool existLeftWall = false;
    bool existRightWall = false;
    for (int j = x; j >= 0; j--) {
        if (arr[y][j] == WALL) {
            start = j;
            existLeftWall = true;
            break;
        }
        visited[y][j] = 1;
    }
    for (int j = x; j < W; j++) {
        if (arr[y][j] == WALL) {
            end = j;
            existRightWall = true;
            break;
        }
        visited[y][j] = 1;
    }
    return (existLeftWall && existRightWall);
}

void fillWater(int y, int start, int end) {
    for (int i = y; i < H; i++) {
        for (int j = start; j <= end; j++) {
            if (arr[i][j] == EMPTY) {
                arr[i][j] = WATER;
                visited[i][j] = 1;
            }
        }
    }
}

int countWater() {
    int count = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (arr[i][j] == WATER) {
                count++;
            }
        }
    }
    return count;
}

void solve() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j] == 0 && arr[i][j] == EMPTY) {
                int start, end;
                if (check(i, j, start, end)) {
                    fillWater(i, start, end);
                }
            }
        }
    }
    cout << countWater() << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}