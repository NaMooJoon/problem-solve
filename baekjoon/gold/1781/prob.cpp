#include <bits/stdc++.h>
using namespace std;
#define SIZE    200000

typedef struct _prob {
    int time;
    int count;
} Prob;

int comp(Prob prob1, Prob prob2) {
    return prob1.time < prob2.time;
}

int N;
Prob problems[SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> problems[i].time >> problems[i].count;
    }
    sort(problems, problems + N, comp);
}

void solve() {
    long long answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < N; i++) {
        pq.push(problems[i].count);
        if (pq.size() > problems[i].time) {
            pq.pop();
        }
    }
    while (pq.size()) {
        answer += pq.top();
        pq.pop();
    }
    cout << answer << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}