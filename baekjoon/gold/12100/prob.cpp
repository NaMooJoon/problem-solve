#include <bits/stdc++.h>
using namespace std;
#define SIZE    20

int N;
int arr[SIZE][SIZE];
int answer = 0;

typedef enum _dir {
    UP = 0,
    DOWN,
    LEFT,
    RIGHT,
    N_DIR,
} Dir;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
}

void printArr() {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void _move_left() {
    for (int i = 0; i < N; i++) {
        vector<int> v;
        bool flag = false;
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0) {
                continue;
            }
            if (flag) {
                v.push_back(arr[i][j]);
                flag = false;
                continue;
            }
            if (!v.empty() && v.back() == arr[i][j]) {
                v.pop_back();
                v.push_back(arr[i][j] << 1);
                flag = true;
                continue;
            }
            v.push_back(arr[i][j]);
        }
        for (int j = 0; j < N; j++) {
            if (j < v.size()) {
                arr[i][j] = v[j];
                continue;
            }
            arr[i][j] = 0;
        }
    }
}

void _move_up() {
    for (int j = 0; j < N; j++) {
        vector<int> v;
        bool flag  = false;
        for (int i = 0; i < N; i++) {
            if (arr[i][j] == 0) {
                continue;
            }
            if (flag) {
                v.push_back(arr[i][j]);
                flag = false;
                continue;
            }
            if (!v.empty() && v.back() == arr[i][j]) {
                v.pop_back();
                v.push_back(arr[i][j] << 1);
                flag = true;
                continue;
            }
            v.push_back(arr[i][j]);
        }
        for (int i = 0; i < N; i++) {
            if (i < v.size()) {
                arr[i][j] = v[i];
                continue;
            }
            arr[i][j] = 0;
        }
    }
}


void _move_right() {
    for (int i = 0; i < N; i++) {
        vector<int> v;
        bool flag = false;
        for (int j = N - 1; j >= 0; j--) {
            if (arr[i][j] == 0) {
                continue;
            }
            if (flag) {
                v.push_back(arr[i][j]);
                flag = false;
                continue;
            }
            if (!v.empty() && v.back() == arr[i][j]) {
                v.pop_back();
                v.push_back(arr[i][j] << 1);
                flag = true;
                continue;
            }
            v.push_back(arr[i][j]);
        }
        int idx = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (idx < v.size()) {
                arr[i][j] = v[idx++];
                continue;
            }
            arr[i][j] = 0;
        }
    }
}

void _move_down() {
    for (int j = 0; j < N; j++) {
        vector<int> v;
        bool flag = false;
        for (int i = N - 1; i >= 0; i--) {
            if (arr[i][j] == 0) {
                continue;
            }
            if (flag) {
                v.push_back(arr[i][j]);
                flag = false;
                continue;
            }
            if (!v.empty() && v.back() == arr[i][j]) {
                v.pop_back();
                v.push_back(arr[i][j] << 1);
                flag = true;
                continue;
            }
            v.push_back(arr[i][j]);
        }
        int idx = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (idx < v.size()) {
                arr[i][j] = v[idx++];
                continue;
            }
            arr[i][j] = 0;
        }
    }
}

int getMaxNumberInArr() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ret = max(ret, arr[i][j]);
        }
    }
    return ret;
}

void move(Dir dir, int depth) {
    int copy[SIZE][SIZE];

    if (dir == UP) { _move_up(); }
    if (dir == DOWN) { _move_down(); }
    if (dir == RIGHT) { _move_right(); }
    if (dir == LEFT) { _move_left(); }
    
    depth = depth + 1;
    if (depth == 5) {
        int _max = getMaxNumberInArr();
        answer = max(_max, answer);
        return;
    }

    memcpy(copy, arr, sizeof(arr));
    for (int i = 0; i < N_DIR; i++) {
        move((Dir) i, depth);
        memcpy(arr, copy, sizeof(arr));
    }
}

void solve() {
    int copy[SIZE][SIZE];
    memcpy(copy, arr, sizeof(arr));
    for (int i = 0; i < N_DIR; i++) {
        move((Dir) i, 0);
        memcpy(arr, copy, sizeof(arr));
    }
    cout << answer << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}