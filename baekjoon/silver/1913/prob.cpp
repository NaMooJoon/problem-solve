#include <bits/stdc++.h>
using namespace std;
#define SIZE    1000

typedef enum _dir {
    RIGHT,
    DOWN,
    LEFT,
    UP,
    N_DIR
} Dir;
const int dy[N_DIR] = {0, 1, 0, -1};
const int dx[N_DIR] = {1, 0, -1, 0};
int arr[SIZE][SIZE];

void print_arr(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    int N, target;
    cin >> N >> target;

    int center_y = N / 2, center_x = N / 2;
    int num = 1;
    arr[center_y][center_x] = num++;

    int level = 1;
    while (level <= N / 2) {
        int idx = 0;
        int y = center_y - level;
        int x = center_x - level;
        while (idx != N_DIR) {
            int ny = y + dy[idx];
            int nx = x + dx[idx];
            if (ny < center_y - level || ny > center_y + level || nx < center_x - level || nx > center_x + level) {
                idx++;
                continue;
            }
            arr[ny][nx] = num++;
            y = ny;
            x = nx;
        }
        level = level + 1;
    }

    print_arr(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == target) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
    }


    return 0;
}