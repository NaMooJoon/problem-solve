#include <bits/stdc++.h>
using namespace std;
#define SIZE    10

int main(void) {
    int N, num, area;
    int answer = 0;
    bool visited[SIZE];
    int cow[SIZE];

    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(visited, 0, SIZE);
    memset(cow, 0, SIZE);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num >> area;
        if (visited[num - 1]) {
            if (cow[num - 1] != area) {
                answer++;
                cow[num - 1] = area;
            }
            continue;
        }
        visited[num - 1] = true;
        cow[num - 1] = area;
    }

    cout << answer << '\n';

    return 0;
}