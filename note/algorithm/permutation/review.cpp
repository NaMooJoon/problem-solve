#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    clock_t start, end;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    start = time(NULL);
    do {
        cout << a[0] << " " << a[1] << " " << a[2];
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
    end = time(NULL);

    cout << "Time: " << (double) (end - start);

    return 0;
}