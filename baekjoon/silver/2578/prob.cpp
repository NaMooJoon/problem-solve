#include <bits/stdc++.h>
using namespace std;
#define SIZE    5

int indexOf[SIZE * SIZE + 1];
bool board[SIZE][SIZE];
bool visitedRow[SIZE];
bool visitedCol[SIZE];
bool visitedDesc;
bool visitedAsc;

vector<int> call;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> num;
            indexOf[num] = i * 10 + j;
        }
    }

    for (int i = 0; i < SIZE * SIZE; i++) {
        cin >> num;
        call.push_back(num);
    }
}

int checkRow(int y) {
    for (int j = 0; j < SIZE; j++) {
        if (board[y][j] == 0) {
            return 0;
        }
    }
    visitedRow[y] = 1;
    return 1;
}

int checkCol(int x) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][x] == 0) {
            return 0;
        }
    }
    visitedCol[x] = 1;
    return 1;
}

int checkDescDiagonal() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] == 0) {
            return 0;
        }
    }
    visitedDesc = 1;
    return 1;
}

int checkAscDiagonal() {
    for (int i = 0; i < SIZE; i++) {
        int y = SIZE - i - 1;
        if (board[y][i] == 0) {
            return 0;
        }
    }
    visitedAsc = 1;
    return 1;
}

void printBingo() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            string s = board[i][j] ? "O " : "X ";
            cout << s; 
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve() {

    int count = 0;
    int bingo = 0;

    for (int num : call) {
        int y = indexOf[num] / 10;
        int x = indexOf[num] % 10;

        board[y][x] = 1;
        count++;

        if (visitedRow[y] == 0) {
            bingo += checkRow(y);
        }
        if (visitedCol[x] == 0) {
            bingo += checkCol(x);
        }
        if (y == x && visitedDesc == 0) {
            bingo += checkDescDiagonal();
        }
        if ((SIZE - y - 1 == x) && visitedAsc == 0) {
            bingo += checkAscDiagonal();
        }
        if (bingo >= 3) { break; }
    }
    cout << count << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}