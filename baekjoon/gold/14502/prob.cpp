#include <bits/stdc++.h>
using namespace std;
#define SIZE    9 
#define WALL    1
#define EMPTY   0

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int height, width;
int board[SIZE][SIZE];
bool visited[SIZE][SIZE];

bool isEmpty(int point) {
    int i = point / width;
    int j = point % width;
    return (board[i][j] == 0);
}

void setSpace(int point, int val) {
    int i = point / width;
    int j = point % width;
    board[i][j] = val;
}

void setAllSpace(int point1, int point2, int point3, int val) {
    setSpace(point1, val);
    setSpace(point2, val);
    setSpace(point3, val);
}

void DFS(int y, int x) {
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
        if (board[ny][nx]) {
            continue;
        }
        DFS(ny, nx);
    }
}

void spreadBirus() {
    fill(&visited[0][0], &visited[SIZE - 1][SIZE - 1], 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 1) {
                visited[i][j] = 1;
            }
            if (board[i][j] == 2) {
                DFS(i, j);
            }
        }
    }
}

int countSafe() {
    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (visited[i][j] == 0){
                count++;
            }
        }
    }
    return count;
}

void printBoard(string s) {
    cout << '\n';
    cout << s << '\n';
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> height >> width;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> board[i][j];
        }
    }

    int max = 0, n;
    int p_size = height * width;
    for (int p1 = 0; p1 < p_size; p1++) {
        for (int p2 = p1 + 1; p2 < p_size; p2++) {
            for (int p3 = p2 + 1; p3 < p_size; p3++) {
                if (isEmpty(p1) && isEmpty(p2) && isEmpty(p3)) {
                    setAllSpace(p1, p2, p3, WALL);
                    spreadBirus();
                    n = countSafe();
                    max = (max < n)? n : max;
                    setAllSpace(p1, p2, p3, EMPTY);
                }
            }
        }
    }

    cout << max << '\n';


    return 0;  
}
