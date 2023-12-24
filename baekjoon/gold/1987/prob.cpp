/* 1987, 알파벳 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE    32

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
int R, C;
char arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
bool checkAlphabet[SIZE];
int answer = 0;

void findMaximumMove(int depth, int y, int x) {

    answer = max(answer, depth);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
            continue;
        }
        if (visited[ny][nx]) {
            continue;
        }
        if (checkAlphabet[arr[ny][nx] - 'A']) {
            continue;
        }
        visited[ny][nx] = 1;
        checkAlphabet[arr[ny][nx] - 'A'] = 1;
        findMaximumMove(depth + 1, ny, nx);
        visited[ny][nx] = 0;
        checkAlphabet[arr[ny][nx] - 'A'] = 0;
    }

}


int main (void) {

    string s;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            arr[i][j] = s[j];
        }
    }

    visited[0][0] = 1;
    checkAlphabet[arr[0][0] - 'A'] = 1;
    findMaximumMove(1, 0, 0);

    cout << answer << '\n';

    return 0;
}