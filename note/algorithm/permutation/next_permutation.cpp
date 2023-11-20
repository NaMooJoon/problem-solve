#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    // int a[] = {1, 2, 3};
    vector<int> a = {2, 1, 3, 200, 100};
    sort(a.begin(), a.end());
    do {
        cout << a[0] << ' ' << a[1] << ' ' << a[2];
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}