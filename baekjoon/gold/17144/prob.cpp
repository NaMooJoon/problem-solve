#include <bits/stdc++.h>
using namespace std;
#define SIZE    50

int R, C, T;
int arr[SIZE][SIZE];
pair<int,int> pos[2];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> T;
    int idx = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                pos[idx++] = {i, j};
            }
        }
    }
}

void printArr() {
    cout << '\n';
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void printVec(deque<int>& v) {
    cout << '\n';
    for (int u : v) {
        cout << u << ' ';
    }
    cout << '\n';
}

struct node
{
    int y;
    int x;
    int amount;
};


void spread() {
    const int dy[4] = {-1, 1, 0, 0};
    const int dx[4] = {0, 0, -1, 1};

    vector<pair<int,int>> pos;
    vector<int> amountV;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] > 0) {
                pos.push_back({i, j});
                amountV.push_back(arr[i][j]);
            }
        }
    }

    int idx = 0;
    for (auto& p : pos) {
        int i = p.first;
        int j = p.second;
        int amount = amountV[idx++];

        int spreadCount = 0;
        int spreadAmount = amount / 5;

        for (int idx = 0; idx < 4; idx++) {
            int y = i + dy[idx];
            int x = j + dx[idx];
            if (y < 0 || y >= R || x < 0 || x >= C || arr[y][x] == -1) {
                continue;
            }
            spreadCount++;
            arr[y][x] += spreadAmount;
        }
        int restAmount = arr[i][j] - spreadAmount * spreadCount;
        arr[i][j] = restAmount;
    }
}

void readUpperClean(int upperY, int upperX, deque<int>& UQ) {
    // RIGHT
    for (int j = upperX + 1; j < C; j++) {
        UQ.push_back(arr[upperY][j]);
    }
    // UP
    for (int i = upperY - 1; i >= 0; i--) {
        UQ.push_back(arr[i][C - 1]);
    }
    // LEFT
    for (int j = C - 2; j >= 0; j--) {
        UQ.push_back(arr[0][j]);
    }
    // DOWN
    for (int i = 1; i < upperY; i++) {
        UQ.push_back(arr[i][0]);
    }
}

void writeUpperClean(int upperY, int upperX, deque<int>& UQ) {
    // RIGHT
    for (int j = upperX + 1; j < C; j++) {
        arr[upperY][j] = UQ.front();
        UQ.pop_front();
    }
    // UP
    for (int i = upperY - 1; i >= 0; i--) {
        arr[i][C - 1] = UQ.front();
        UQ.pop_front();
    }
    // LEFT
    for (int j = C - 2; j >= 0; j--) {
        arr[0][j] = UQ.front();
        UQ.pop_front();
    }
    // DOWN
    for (int i = 1; i < upperY; i++) {
        arr[i][0] = UQ.front();
        UQ.pop_front();
    }
}

void readLowerClean(int lowerY, int lowerX, deque<int>& LQ) {
    // RIGHT
    for (int j = lowerX + 1; j < C; j++) {
        LQ.push_back(arr[lowerY][j]);
    }
    // DOWN
    for (int i = lowerY + 1; i < R; i++) {
        LQ.push_back(arr[i][C - 1]);
    }
    // LEFT
    for (int j = C - 2; j >= 0; j--) {
        LQ.push_back(arr[R - 1][j]);
    }
    // UP
    for (int i = R - 2; i > lowerY; i--) {
        LQ.push_back(arr[i][0]);
    }
}

void writeLowerClean(int lowerY, int lowerX, deque<int>& LQ) {
    // RIGHT
    for (int j = lowerX + 1; j < C; j++) {
        arr[lowerY][j] = LQ.front();
        LQ.pop_front();
    }
    // DOWN
    for (int i = lowerY + 1; i < R; i++) {
        arr[i][C - 1] = LQ.front();
        LQ.pop_front();
    }
    // LEFT
    for (int j = C - 2; j >= 0; j--) {
        arr[R - 1][j] = LQ.front();
        LQ.pop_front();
    }
    // UP
    for (int i = R - 2; i > lowerY; i--) {
        arr[i][0] = LQ.front();
        LQ.pop_front();
    }
}

void cleaner() {
    int upperY = pos[0].first;
    int upperX = pos[0].second;
    deque<int> UQ;
    readUpperClean(upperY, upperX, UQ);
    UQ.pop_back(); // cleaner suck it.
    UQ.push_front(0); // cleaner push it.
    writeUpperClean(upperY, upperX, UQ);
    
    int lowerY = pos[1].first;
    int lowerX = pos[1].second;
    deque<int> LQ;
    readLowerClean(lowerY, lowerX, LQ);
    LQ.pop_back(); // cleaner suck it.
    LQ.push_front(0); // cleaner push it.
    writeLowerClean(lowerY, lowerX, LQ); 
}

int getRest() {
    int total = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] != -1) {
                total += arr[i][j];
            }
        }
    }
    return total;
}

void solve() {
    for (int time = 0; time < T; time++) {
        spread();
        cleaner();
    }
    cout << getRest() << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}