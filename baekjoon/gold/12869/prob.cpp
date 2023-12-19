/* 12869번, 뮤탈리스크 */
#include <bits/stdc++.h>
using namespace std;

int depth[61][61][61];
int N, times = 0;

int BFS(int a, int b = 0, int c = 0) {
    int attack[3] = {1, 3, 9};
    vector<int> v = {a, b, c};
    depth[a][b][c] = 1;

    queue<vector<int>> q;
    q.push(v);
    
    while (q.size()) {
        int a = q.front()[0];
        int b = q.front()[1];
        int c = q.front()[2];
        q.pop();

        do {
            int na = max(0, a - attack[0]);
            int nb = max(0, b - attack[1]);
            int nc = max(0, c - attack[2]);
            
            if (depth[0][0][0] != 0) {
                return depth[0][0][0] - 1;
            }
            vector<int> newV = {na, nb, nc};
            if (depth[na][nb][nc] == 0) {
                depth[na][nb][nc] = depth[a][b][c] + 1;
                q.push(newV);
            }
        } while(next_permutation(attack, attack + 3));
    }
    return -1;
}

int main (void)
{
    int scv[3] = {0, 0, 0};

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> scv[i];
    }
    cout << BFS(scv[0], scv[1], scv[2]) << '\n';

    return 0;
}