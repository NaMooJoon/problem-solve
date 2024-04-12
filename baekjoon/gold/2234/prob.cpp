#include <bits/stdc++.h>
using namespace std;
#define SIZE    50

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int M, N;
int inputArr[SIZE][SIZE];
int areaArr[SIZE][SIZE];
bool visited[SIZE][SIZE];


int roomSize[SIZE * SIZE];
int numOfRoom, maxRoomSize, maxLinkedRoomSize;


void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> inputArr[i][j];
        }
    }
}

void printAreaArr() {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << areaArr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void DFS(int y, int x, int area) {
    visited[y][x] = 1;
    areaArr[y][x] = area;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (inputArr[y][x] & (1 << i)) {
            continue;            
        }
        if (ny < 0 || ny >= N || nx < 0 || nx > M) {
            continue;
        }
        if (visited[ny][nx]) {
            continue;
        }
        DFS(ny, nx, area);
    }
}

void readInputArr() {
    numOfRoom = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                DFS(i, j, numOfRoom++);
            }
        }
    }
}

void checkMaxRoomSize() {
    maxRoomSize = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            roomSize[areaArr[i][j]]++;
        }
    }
    for (int i = 0; i < numOfRoom; i++) {
        maxRoomSize = max(maxRoomSize, roomSize[i]);
    }
}

bool _isLinked(int y, int x, int target) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
            continue;
        }
        if (visited[ny][nx]) {
            continue;
        }
        if (areaArr[ny][nx] == target) {
            return true;
        }
        if (areaArr[ny][nx] != areaArr[y][x]) {
            continue;
        }
        if (_isLinked(ny, nx, target)) {
            return true;
        }
    }
    return false;
}

bool isLinked(int area1, int area2) {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (areaArr[i][j] == area1) {
                return _isLinked(i, j, area2);
            }
        }
    }
    return false;
}

void checkMaxLinkedRoomSize() {
    maxLinkedRoomSize = 0;
    for (int i = 0; i < numOfRoom - 1; i++) {
        for (int j = i + 1; j < numOfRoom; j++) {
            int twoRoomSize = roomSize[i] + roomSize[j];
            if (maxLinkedRoomSize < twoRoomSize && isLinked(i, j)) {
                maxLinkedRoomSize = twoRoomSize;
            }
        }
    }
}

void solve() {
    int arr[SIZE][SIZE];
    memset(arr, 0, sizeof(arr));

    readInputArr();
    checkMaxRoomSize();
    checkMaxLinkedRoomSize();

    cout << numOfRoom << '\n' << maxRoomSize << '\n' << maxLinkedRoomSize << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}