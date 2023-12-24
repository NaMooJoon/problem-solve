#include <bits/stdc++.
using namespace std;
#define SIZE    500004
#define MAX_POS 500000

bool visited[SIZE];

int BFS(int curr, int target) {

    int answer = 0;
    queue<pair<int,int>> q;
    visited[curr] = 1;

    q.push({curr, 0});
    while (q.size()) {
        int dest;
        int curr = q.front().first; 
        int depth = q.front().second;
        q.pop();

        dest = target + (depth * (depth + 1) / 2);
        // if (depth== 385) {
            // cout << curr << ' ' << dest << '\n';
        // }

        if (dest > MAX_POS) {
            answer = -1;
            break;
        }
        if (curr == dest) {
            answer = depth;
            break;
        }

        for (int next : {curr + 1, curr - 1, curr * 2}) {

            if (next < 0 || next > MAX_POS) {
                continue;
            }

            // if (visited[next] == 0 || 
            //     ((dest + depth - 1) <= next && next <= (dest + 2 * depth + 1))) {
            if (visited[next] == 0 ) {
                visited[next] = 1;
                q.push({next, depth + 1});
            } 
        }
    }
    return answer;
}

int main (void)
{
    int N, K;

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(nullptr);

    cin >> N >> K;
    cout << BFS(N, K) << '\n';

    return 0;
}