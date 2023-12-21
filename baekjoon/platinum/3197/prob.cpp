/* 3197번, 백조의 호수 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE        1501

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

char arr[SIZE][SIZE];
bool visited[SIZE][SIZE];
bool bird_visited[SIZE][SIZE];
int height, width;

void printBoard() {
    cout << '\n';
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (arr[i][j] == '.' && bird_visited[i][j]) {
                cout << 'L';
                continue;
            }
            cout << arr[i][j];
        }
        cout << '\n';
    }
}


void meltOneday(queue<int>& q, queue<int>& temp) {

    while (q.size()) {

        int y = q.front() / 10000;
        int x = q.front() % 10000;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
                continue;
            }
            if (visited[ny][nx]) {
                continue;
            }
            visited[ny][nx] = 1;
            if (arr[ny][nx] == 'X') {
                arr[ny][nx] = '.';
                temp.push(ny * 10000 + nx);
            }
            // q.push(ny * 10000 + nx);
        }
    }
}

bool birdCanMeet(queue<int>& queueBird, queue<int>& temp) {

    while (queueBird.size()) {

        int y = queueBird.front() / 10000;
        int x = queueBird.front() % 10000;
        queueBird.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
                continue;
            }
            if (bird_visited[ny][nx]) {
                continue;
            }
            bird_visited[ny][nx] = 1;
            if (arr[ny][nx] == 'X') {
                temp.push(ny * 10000 + nx);
                continue;
            }
            if (arr[ny][nx] == 'L') {
                return true;
            }
            queueBird.push(ny * 10000 + nx);
        }
    }
    return false;
}

int solve(int start) {

    int countDay = 0;
    queue<int> q;
    queue<int> queuebird;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (arr[i][j] != 'X') {
                q.push(i * 10000 + j);
            }
        }
    }
    queuebird.push(start);

    while (q.size()) {

        queue<int> temp;
        queue<int> tempBird;    

        if (birdCanMeet(queuebird, tempBird)) {
            break;
        }

        meltOneday(q, temp);
        countDay++;

        // printBoard();
        // printBird();

        q = temp;
        queuebird = tempBird;
    }
    return countDay;
}

int main (void)
{
    bool flag = true;
    int bird_pos;
    string s;

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> height >> width;
    for (int i = 0; i < height; i++) {
        cin >> s;
        for (int j = 0; j < width; j++) {
            arr[i][j] = s[j];
            if (flag && s[j] == 'L') {
                bird_visited[i][j] = 1;
                bird_pos = i * 10000 + j;
                flag = false;
            }
        }
    }

    cout << solve(bird_pos) << '\n';
    
    return 0;
}