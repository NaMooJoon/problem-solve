/* 14497번, 주난의 난 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE        301

int height, width;
int targetX, targetY;
int X, Y;
int arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

void jump(queue<int>& q, queue<int>& temp) {

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
            if (arr[ny][nx] != 0) {
                arr[ny][nx] = 0;
                visited[ny][nx] = true;
                temp.push(ny * 1000 + nx);
                continue;
            }
            q.push(ny * 1000 + nx);
        }
    }

}

int solve() {

    int jumpCount = 0;
    queue<int> q;

    q.push(Y * 1000 + X);
    while (arr[targetY][targetX]) {
        queue<int> temp;

        jump(q, temp);
        q = temp;

        jumpCount++;
    }


    return jumpCount;
}


int main (void) {

    string s;

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> height >> width;
    cin >> Y >> X >> targetY >> targetX;
    X--; Y--; targetX--; targetY--;

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