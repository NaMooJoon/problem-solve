#include <bits/stdc++.h>
using namespace std;
#define SIZE    50

/* UP: 0, DOWN: 1, LEFT: 2, RIGHT: 3 */
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M;
int num[8];
int arr[SIZE][SIZE];
vector<pair<int,int>> magics;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int d, s;
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        magics.push_back({(d - 1), s});
    }
}

inline bool isInBoundary(int y, int x) {
    return (y >= 0 && y < N && x >= 0 && x < N);
}

int nextDir(int idx) {
    if (idx == 2) { // left
        return 1; // down
    }
    if (idx == 1) { // down
        return 3; // right
    }
    if (idx == 3) { // right
        return 0; // up
    }
    if (idx == 0) { // up 
        return 2; // left
    }
    return -1;
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

void blizard(int dirIdx, int length) {
    int y = N / 2, x = N / 2;
    for (int i = 0; i < length; i++) {
        y = y + dy[dirIdx];
        x = x + dx[dirIdx];
        arr[y][x] = 0;
    }
}

void arr2Vec(vector<int>& vec) {
    int y = N / 2, x = N / 2;
    int dirIdx = 2; // left
    int dirLen = 1;
    
    while (isInBoundary(y,x)) {
        for (int i = 0; i < dirLen; i++) {
            y = y + dy[dirIdx];
            x = x + dx[dirIdx];
            vec.push_back(arr[y][x]);
        }
        dirIdx = nextDir(dirIdx);
        for (int i = 0; i < dirLen; i++) {
            y = y + dy[dirIdx];
            x = x + dx[dirIdx];
            vec.push_back(arr[y][x]);
        }
        dirIdx = nextDir(dirIdx);
        dirLen = dirLen + 1;
    }
}

void vec2Arr(vector<int>& vec) {
    int y = N / 2, x = N / 2;
    int dirIdx = 2; // left
    int dirLen = 1;
    
    int idx = 0, size = vec.size();;
    memset(arr, 0, sizeof(arr));
    while (true) {

        for (int i = 0; i < dirLen; i++) {
            y = y + dy[dirIdx];
            x = x + dx[dirIdx];
            if (!isInBoundary(y, x)) return;
            arr[y][x] = (idx < size)? vec[idx++] : 0;
        }
        dirIdx = nextDir(dirIdx);
        for (int i = 0; i < dirLen; i++) {
            y = y + dy[dirIdx];
            x = x + dx[dirIdx];
            if (!isInBoundary(y, x)) return;
            arr[y][x] = (idx < size)? vec[idx++] : 0;
        }
        dirIdx = nextDir(dirIdx);
        dirLen = dirLen + 1;
    }
}

void adjustArr() {
    vector<int> vec;
    vector<int> vecWithoutBlank;

    arr2Vec(vec);
    for (int v : vec) {
        if (v > 0) { vecWithoutBlank.push_back(v); }
    }
    vec2Arr(vecWithoutBlank);
}

void blastArr() {
    vector<int> vec;
    vector<int> vecAfterBlast;

    arr2Vec(vec);

    bool flag = false;
    int startIdx = 0;
    int endIdx = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[startIdx] == vec[i]) {
            endIdx = i;
            continue;
        } 
        int count = endIdx - startIdx + 1;
        if (count < 4) {
            for (int j = startIdx; j <= endIdx; j++) {
                vecAfterBlast.push_back(vec[j]);
            }
        } else {
            num[vec[startIdx]] += count;
            if (vec[startIdx] != 0) flag = true;
        }
        startIdx = i;
        endIdx = i;
    }
    if (flag) {
        vec2Arr(vecAfterBlast);
        blastArr();
    }
}

void changeArr() {
    vector<int> vec;
    vector<int> vecAfterChange;

    arr2Vec(vec); 
    int startIdx = 0;
    int endIdx = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[startIdx] == vec[i]) {
            endIdx = i;
            continue;
        } 
        int count = endIdx - startIdx + 1;
        vecAfterChange.push_back(count);
        vecAfterChange.push_back(vec[startIdx]);

        startIdx = i;
        endIdx = i;
    }
    vec2Arr(vecAfterChange);
}

void printAnswer() {
    int answer = 1 * num[1] + 2 * num[2] + 3 * num[3];
    cout << answer << '\n';
}

void solve() {
    for (auto& magic : magics) {
        blizard(magic.first, magic.second);
        adjustArr();
        blastArr();
        changeArr();
    }
    printAnswer();
}

int main(void) {
    inputInit();
    solve();
    return 0;
}