#include <bits/stdc++.h>
using namespace std;

#define MAX_TIME    101
#define NUM         3

int main (void)
{
    int start, end;
    int A, B, C;
    int time[MAX_TIME] = {0};
    int answer = 0;

    cin >> A >> B >> C;
    for (int i = 0; i < NUM; i++) {
        cin >> start >> end;
        for (int j = start; j < end; j++) {
            time[j]++;
        }
    }

    for (int i = 0; i < MAX_TIME; i++) {
        if (time[i] == 0) {
            continue;
        } else if (time[i] == 1) {
            answer += A;
        } else if (time[i] == 2) {
            answer += 2 * B;
        } else if (time[i] == 3) {
            answer += 3 * C;
        }
    }
    cout << answer << '\n';

    return 0;
}