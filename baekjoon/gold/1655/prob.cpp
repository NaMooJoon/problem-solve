#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, less<int>> pqGreater;
priority_queue<int, vector<int>, greater<int>> pqLess;

int main (void)
{
    int N, num;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        
        if (pqGreater.empty()) {
            pqGreater.push(num);
        }
        else if (pqGreater.size() == pqLess.size()) {
            pqGreater.push(num);
        }
        else if (pqGreater.size() > pqLess.size()) {
            pqLess.push(num);
        }

        if (!pqGreater.empty() && !pqLess.empty() && (pqGreater.top() > pqLess.top())) {
            int fromGreater = pqGreater.top();
            int fromLess = pqLess.top();

            pqGreater.pop();
            pqLess.pop();

            pqGreater.push(fromLess);
            pqLess.push(fromGreater);
        }

        cout << pqGreater.top() << '\n';
    }

    return 0;
}