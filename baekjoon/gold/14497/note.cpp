/* 14497번, 주난의 난 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE        301

int height, width;
int X, Y;
char arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

vector<int> v;
void jump(queue<int>& q) {


    while (q.size()) {

        int y = q.front() / 1000;
        int x = q.front() % 1000;
        q.pop();

        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            if (arr[ny][nx] == 3) {
                v.clear();
                return;
            }
            if (arr[ny][nx] == 1) {
                visited[ny][nx] = true;
                v.push_back(ny * 1000 + nx);
                continue;
            }
            q.push(ny * 1000 + nx);
        }
    }
}

int solve() {

    int jumpCount = 0;
    queue<int> q;

    while (true) {

        memset(visited, 0, sizeof(visited));
        q.push(Y * 1000 + X);

        v.clear();
        jump(q);
        jumpCount++;

        if (v.empty()) {
            break;
        }
        for (int i : v) {
            arr[i  / 1000][i % 1000] = 0;
        }
    }
    return jumpCount;
}


int main (void) {

    string s;
    int targetX, targetY;

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> height >> width;
    cin >> Y >> X >> targetY >> targetX;
    Y--; X--; targetY--; targetX--;

    for (int i = 0; i < height; i++) {
        cin >> s;
        for (int j = 0; j < width; j++) {
            if (s[j] == '#') {
                arr[i][j] = 3;
            } else if (s[j] == '*') {
                arr[i][j] = 2;
            } else {
                arr[i][j] = s[j] - '0';
            }
        }
    }
    cout << solve() << '\n';

    return 0;
}