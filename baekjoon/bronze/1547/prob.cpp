#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int M;
    int x, y;
    int haveBall = 1;

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> M;

    while (M--)
    {
        cin >> x >> y;
        if (x == haveBall) {
            haveBall = y;
        }
        else if (y == haveBall) {
            haveBall = x;
        }
    }

    cout << haveBall << '\n';

    return 0;
}