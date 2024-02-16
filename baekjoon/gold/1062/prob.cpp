#include <bits/stdc++.h>
using namespace std;
#define SIZE    50

int N, K, answer = 0;
int words_mask[SIZE];

void inputInit() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(words_mask, 0, sizeof(words_mask));

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (char ch : s) {
            words_mask[i] |= (1 << (ch - 'a'));
        }
    }
}

int getNumberOfWordToRead(int mask) {
    int count = 0;
    for (int word : words_mask) {
        if (word && (word & mask) == word) {
            count++;
        }
    }
    return count;
}

int teach(int index, int rest, int mask) {
    if (index == 26) {
        return getNumberOfWordToRead(mask);
    }
    if (rest <= 0) {
        return getNumberOfWordToRead(mask);
    }
    int thisTime = teach(index + 1, rest - 1, mask | (1 << index));
    if (index == 'a' - 'a' || index == 'c'- 'a' ||index == 'i'- 'a' ||index == 'n'- 'a' ||index == 't'- 'a') {
        return thisTime;
    }
    int nextTime = teach(index + 1, rest, mask);
    return max(thisTime, nextTime);
}

void solve() {
    answer = teach(0, K, 0);
}

void printAnswer() {
    cout << answer << '\n';
}

int main(void) {
    inputInit();
    solve();
    printAnswer();
    return 0;
}