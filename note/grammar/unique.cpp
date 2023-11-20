#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main (void)
{
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
        v.push_back(i);
    }
    for (int i : v) {
        cout << i << " ";
    }
    cout << '\n';

    auto it = unique(v.begin(), v.end());
    cout << it - v.begin() << '\n';
    for (int i : v) {
        cout << i << " ";
    }
    cout << '\n';

    v.erase(it, v.end());
    for (int i : v) {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}