/* 13913번, 숨바꼭질 4 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE    100001

int N, K;
int visited[SIZE * 2];
int beforeIdx[SIZE * 2];


void printResult(int dest) {
    stack<int> st;
    while (dest != N) {
        st.push(dest);
        dest = beforeIdx[dest];
    }
    st.push(dest);

    cout << st.size() - 1 << '\n';
    while (st.size()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';
}


void BFS(int curr, int dest) {

    queue<int> q;
    q.push(curr);
    visited[curr] = 1;

    while (q.size()) {
        int next = q.front(); q.pop();
        if (next < 0 || next >= SIZE) {
            continue;
        }
        if (next == dest) {
            printResult(dest);
            break;
        }
        for (int idx : {next + 1, next - 1, next * 2}) {
            if (visited[idx] == 0) {
                visited[idx] = 1;
                beforeIdx[idx] = next;
                q.push(idx);
            }
        }
    }
}

int main(void) 
{

    cin >> N >> K;

    BFS(N, K);

    return 0;
}