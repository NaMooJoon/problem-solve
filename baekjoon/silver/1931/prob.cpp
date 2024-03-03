#include <bits/stdc++.h>
using namespace std;
#define SIZE        100000

typedef struct _time {
    int start;
    int end;
} Time;

int N;
Time times[SIZE];

int comp(Time time1,  Time time2) {
    return (time1.end < time2.end || (time1.end == time2.end && time1.start < time2.start));
}

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> times[i].start >> times[i].end;
    }
    sort(times, times + N, comp);
}

void solve() {
    int answer = 0;
    int end = 0;
    for (int i = 0; i < N; i++) {
        if (end <= times[i].start) {
            answer++;
            end = times[i].end;
        }
    }
    cout << answer << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}