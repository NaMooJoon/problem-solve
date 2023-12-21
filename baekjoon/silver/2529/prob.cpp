#include <bits/stdc++.h>
using namespace std;
#define SIZE    10

int N;
char sign[SIZE];
bool visited[SIZE];
long long answer_max = -1;
long long answer_min = LONG_MAX;

bool isSatisfied(int depth, int a, int b) {

    if (sign[depth] == '<') {
        return (a < b);
    }
    if (sign[depth] == '>') {
        return (a > b);
    }
    return false;
}

void DFS(int depth, int prev, string s) {

    if (depth == N) {
        answer_max = max(answer_max, stoll(s));
        answer_min = min(answer_min, stoll(s));
        return;
    }

    for (int n : {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        if (visited[n]) {
            continue;
        }
        if (!isSatisfied(depth, prev, n)) {
            continue;
        }
        visited[n] = 1;
        s.push_back('0' + n);

        DFS(depth + 1, n, s);

        visited[n] = 0;
        s.pop_back();
    }

}

int main (void) {

    string s;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sign[i];
    }
    for (int i = 0; i < SIZE; i++) {
        s.push_back('0' + i);
        visited[i] = 1;
        DFS(0, i, s);
        s.pop_back();
        visited[i] = 0;
    }

    string _max = to_string(answer_max);
    string _min = to_string(answer_min);
    if (_min.length() == _max.length() - 1) {
        _min = "0" + _min;
    }

    cout << _max << '\n';
    cout << _min << '\n';

    return 0;
}