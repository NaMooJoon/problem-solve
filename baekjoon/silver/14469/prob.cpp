#include <bits/stdc++.h>
using namespace std;
#define SIZE    128

typedef struct _cow {
    int start;
    int loading;
} Cow;

int comp(Cow cow1, Cow cow2) {
    return (cow1.start < cow2.start);
}

int N;
Cow cowTimes[SIZE];


void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cowTimes[i].start >> cowTimes[i].loading;
    }
    sort(cowTimes, cowTimes + N, comp);
}

void solve() {
    int time = 0;
    int idx = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    while (idx < N) {
        while (time >= cowTimes[idx].start) {
            pq.push(cowTimes[idx].loading);
            idx++;
        }
        if (pq.size()) {
            time += pq.top() - 1;
            pq.pop();
        }
        time++;
    }
    while (pq.size()) {
       time += pq.top();
       pq.pop();
    }
    cout << time << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}