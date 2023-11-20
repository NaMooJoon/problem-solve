#include <bits/stdc++.h>
#define SIZE        50
using namespace std;
/* By using BFS algorithm, find longest search times */

vector<int> relationship[SIZE + 1];

int bfs (int n)
{
    queue<int> q;
    int visited[SIZE + 1] = {0}, max = 0;
    visited[n] = 1;
    q.push(n);
    while (q.size())
    {
        int next = q.front(); q.pop();
        for (int con : relationship[next]) {
            if (visited[con] == 0) {
                visited[con] = visited[next] + 1;
                max = (max < visited[con])? visited[con] : max;
                q.push(con);
            }
        }
    }
    return max - 1;
}

int main (void)
{
    int N;
    int a, b, min = SIZE + 1;
    vector<int> v[SIZE];
    
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    while (true)
    {
        cin >> a >> b;
        if (a == -1 && b == -1) {
            break;
        }
        relationship[a].push_back(b);
        relationship[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        int n = bfs(i);
        v[n].push_back(i);
        min = (min > n)? n : min;
    }
    if (min == SIZE + 1) {
        exit(0);
    }
    sort(v[min].begin(), v[min].end());

    cout << min << ' ' << v[min].size() << '\n';
    for (int i : v[min]) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}