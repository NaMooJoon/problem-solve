#include <bits/stdc++.h>
using namespace std;

int duck_idx = 0;
string duck = "quack";
string sound;
bool visited[2500];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> sound;
    memset(visited, 0, sizeof(visited));
}

bool checkOneDuck() {
    bool flag = false;

    for (int i = 0; i < sound.length(); i++) {
        if (visited[i] == 0) {
            if (sound[i] == duck[duck_idx]) {
                visited[i] = 1;
                duck_idx = (duck_idx + 1) % duck.length();
                flag = true;
            }
        }
    }
    if (duck_idx != 0) {
        flag = false;
    }
    return flag;
}

void printResult(int answer) {

    if (duck_idx != 0) {
        cout << "-1" << '\n';
        return;
    }
    for (int i = 0; i < sound.length(); i++) {
        if (visited[i] == 0) {
            cout << "-1" << '\n';
            return;
        }
    }
    
    cout << answer << '\n';
}

void solve() {

    int count = 0;

    while (checkOneDuck()) {
        count++;
    }
    printResult(count);
}

int main(void) {

    inputInit();
    solve();
    return 0;
}