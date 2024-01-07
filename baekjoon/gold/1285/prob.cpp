/* 1285번, 동전 뒤집기 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE    32

int N;
bool coinArray[SIZE][SIZE];
int answer = INT_MAX;

void inputInit() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    string s; 
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            coinArray[i][j] = (s[j] == 'T')? true : false;
        }
    }
}

void printCoinArray(string s) {
    cout << '\n';
    cout << s << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char ch = coinArray[i][j]? 'T' : 'H';
            cout << ch;
        }
        cout << '\n';
    }
}

void turnOverColumn(int idx) {
    for (int i = 0; i < N; i++) {
        coinArray[i][idx] = !coinArray[i][idx];
    }
}

void turnOverRow(int idx) {
    for (int j = 0; j < N; j++) {
        coinArray[idx][j] = !coinArray[idx][j];
    }
}

int countRow(int idx) {
    int count = 0;
    for (int j = 0; j < N; j++) {
        if (coinArray[idx][j]) {
            count++;
        }
    }
    return count;
}

int countCol(int idx) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (coinArray[i][idx]) {
            count++;
        }
    }
    return count;
}

int countBackSizeCoins() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        count += countRow(i);
    }
    return count;
}

void solve() {

    for (int row_bit_mask = 0; row_bit_mask < (1 << N); row_bit_mask++) {
            
        vector<int> col_v, row_v;

        for (int row = 0; row <= N; row++) {
            if ((1 << row) & row_bit_mask) {
                turnOverRow(row);
                row_v.push_back(row);
            }
        }

        for (int col = 0; col <= N; col++) {
            if (countCol(col) > N / 2) {
                turnOverColumn(col);
                col_v.push_back(col);
            }
        }
        
        answer = min(answer, countBackSizeCoins());

        // Restoration
        for (int col : col_v) {
            turnOverColumn(col);
        }
        for (int row : row_v) {
            turnOverRow(row);
        }
    }
    if (answer == INT_MAX) {
        answer = 0;
    }
}

int main(void) {

    inputInit();
    solve();
    
    cout << answer << '\n';

    return 0;
}