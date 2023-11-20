#include <bits/stdc++.h>
using namespace std;

#define SIZE        32

int main (void)
{
    int alphabet[SIZE] = {0};
    int max = -1;
    char in;
    cin.tie(nullptr); cout.tie(nullptr);

    while (cin >> in)
    {
        if ('a' <= in && in <= 'z') {
            alphabet[in - 'a']++;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (max < alphabet[i]) {
            max = alphabet[i];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (max == alphabet[i]) {
            cout << (char) ('a' + i);
        }
    }
    cout << '\n';

    return 0;
}