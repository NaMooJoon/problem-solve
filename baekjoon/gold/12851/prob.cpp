/* 12851번, 숨바꼭질2 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE    200001

bool flag = false;
int answerTime = 0;
int answerBranch = 0;
int visited[SIZE];

typedef struct data {
    int depth;
    int curr;
    int dest;
} Data ;

void BFS(int depth, int curr, int dest) {
    // cout << depth << ' ' << curr << ' ' << dest << '\n';
    queue<Data> q;
    q.push({depth, curr, dest});

    while (q.size()) {
        int depth = q.front().depth;
        int curr = q.front().curr;
        int dest = q.front().dest;
        q.pop();

        if (curr < 0 || curr >= SIZE) {
            continue;
        }
        if (visited[curr] != 0 && visited[curr] < depth) {
            continue;
        }
        visited[curr] = depth;


        if (!flag && curr == dest) {
            answerTime = depth;
            answerBranch = 1;
            flag = true;
        }
        else if (flag && curr == dest && depth == answerTime) {
            answerBranch++;
        }
        else if (flag && depth > answerTime) {
            continue;
        }

        q.push({depth + 1, curr - 1, dest});
        q.push({depth + 1, curr + 1, dest});
        q.push({depth + 1, curr * 2, dest});
    }


}

int main (void)
{
    int N, K;

    cin >> N >> K;

    BFS(0, N, K);

    cout << answerTime << '\n';
    cout << answerBranch << '\n';

    return 0;
}