#include <bits/stdc++.h>
using namespace std;

#define NUM     15000

int main (void)
{
    int n, m;
    int count = 0;
    int item[NUM];

    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        cin >> item[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (item[i] + item[j] == m) {
                count++;
            }
        }
    }
    cout << count << '\n';

    return 0;
}