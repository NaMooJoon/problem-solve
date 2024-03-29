#include <bits/stdc++.h>
using namespace std;
#define SIZE    101

int N, K;
bool multitab[SIZE];
int nextUse[SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> nextUse[i];
    }
}

int getNextPlugIdx(int useIdx) {
    bool copyTab[SIZE];
    memcpy(copyTab, multitab, SIZE);

    stack<int> st;
    for (int i = useIdx; i < K; i++) {
        int tabIdx = nextUse[i];
        if (copyTab[tabIdx] == 1) {
            st.push(tabIdx);
            copyTab[tabIdx] = 0;
        }
    }
    for (int i = 0; i < SIZE ; i++) {
        if (copyTab[i] == 1) {
            st.push(i);
        }
    }

    return st.top();
}

void solve() {
    int idx = 0;
    int numOfUse = 0;
    while (numOfUse < N && idx < K) {
        int tabIdx = nextUse[idx++];
        if (multitab[tabIdx] == 0) {
            multitab[tabIdx] = 1;
            numOfUse++;
        }
    }
    
    int count = 0;
    for (int i = idx; i < K; i++) {
        if (multitab[nextUse[i]] == 1) {
            continue;
        }
        int plugIdx = getNextPlugIdx(i);
        multitab[plugIdx] = 0;
        multitab[nextUse[i]] = 1;
        count++;
    }
    cout << count << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}