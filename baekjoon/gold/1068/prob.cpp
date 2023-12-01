/* 1068, 트리 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE    50

int main (void) {
    int N, parent, root, remove;
    vector<int> vList[SIZE];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> parent;
        if (parent == -1) {
            root = i;
            continue;
        }
        vList[parent].push_back(i);
    }

    cin >> remove;
    if (remove == root) {
        cout << 0 << '\n';
        return 0;
    }

    queue<int> q;
    q.push(remove);

    while (q.size()) {
        int next = q.front(); q.pop();
        for (int id : vList[next]) {
            q.push(id);
        }
        vList[next].clear();
    }
    for (int i = 0; i < N; i++) {
        auto pos = find(vList[i].begin(), vList[i].end(), remove);
        if (pos != vList[i].end()) {
            vList[i].erase(pos);
            break;
        }
    }

    int count = 0;
    q.push(root);
    while (q.size()) {
        int next = q.front(); q.pop();
        if (vList[next].size() == 0) {
            count++;
        }
        for (int id : vList[next]) {
            q.push(id);
        }
    }

    cout << count << '\n';

    return 0;   
}