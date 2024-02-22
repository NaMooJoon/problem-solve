#include <bits/stdc++.h>
using namespace std;
#define SIZE    21

int N;
int classRoom[SIZE][SIZE];
vector<int> whoLike[SIZE * SIZE];
vector<int> order;

void inputInit() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(classRoom, 0, sizeof(classRoom));

    cin >> N;

    int who, like;
    for (int i = 0; i < N * N; i++) {
        cin >> who;
        order.push_back(who);
        for (int j = 0; j < 4; j++) {
            cin >> like;
            whoLike[who].push_back(like);
        }
    }
}

int countAdj(int from, int y, int x) {
    const int dy[4] = {0, 0, 1, -1};
    const int dx[4] = {1, -1, 0, 0};

    int count = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            continue;
        }
        for (int like : whoLike[from]) {
            if (classRoom[ny][nx] == like) {
                count++;
                break;
            }
        }
    }
    return count;
}

int countBlankAdj(int y, int x) {
    const int dy[4] = {0, 0, 1, -1};
    const int dx[4] = {1, -1, 0, 0};

    int count = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            continue;
        }
        if (classRoom[ny][nx] == 0) {
            count++;
        }
    }
    return count; 
}

void flush_queue(queue<int>& q) {
    while (!q.empty()) {
        q.pop();
    }
}

void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << classRoom[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void setSeat(int who) {
    queue<int> q;
    // rule 1
    int maxAdj = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (classRoom[i][j] == 0) {
                int adj = countAdj(who, i, j);
                if (adj > maxAdj) {
                    flush_queue(q);
                    maxAdj = adj;
                } 
                if (adj == maxAdj) {
                    q.push(i * 100 + j);
                }
            }
        }
    }

    if (q.size() == 1) {
        int y = q.front() / 100;
        int x = q.front() % 100;
        classRoom[y][x] = who;
        // print_board();
        return;
    }

    // rule 2
    queue<int> q2;
    int maxBlankAdj = 0;
    while (!q.empty()) {
        int y = q.front() / 100;
        int x = q.front() % 100;
        q.pop();
        int adj = countBlankAdj(y, x);
        if (adj > maxBlankAdj) {
            flush_queue(q2);
            maxBlankAdj = adj;
        }
        if (adj == maxBlankAdj) {
            q2.push(y * 100 + x);
        }
    }

    // rule 3
    int min = INT_MAX;
    while (!q2.empty()) {
        if (q2.front() < min) {
            min = q2.front();
        }
        q2.pop();
    }
    int y = min / 100;
    int x = min % 100;
    classRoom[y][x] = who;
    // print_board();

}

int getSatisfy() {
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            switch (countAdj(classRoom[i][j], i, j))
            {
            case 0:
                total += 0;
                break;
            case 1:
                total += 1;
                break;
            case 2:
                total += 10;
                break;
            case 3:
                total += 100;
                break;
            case 4:
                total += 1000;
                break;
            default:
                break;
            }
        }
    }
    return total;
}

void solve() {
    for (int who : order) {
        setSeat(who);
    }
    int answer = getSatisfy();
    cout << answer << '\n';
}

int main(void) {

    inputInit();
    solve();
    return 0;
}