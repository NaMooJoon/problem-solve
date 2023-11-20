#include <bits/stdc++.h>
using namespace std;

#define MAX     32

int main (void)
{
    int N;
    int ch[MAX] = {0};
    string name;
    string output = "";

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name;
        ch[name[0] - 'a']++;
    }
    for (int i = 0; i < MAX; i++) {
        if (ch[i] >= 5) {
            output += (char) ('a' + i);
        }
    }
    if (output == "") {
        cout << "PREDAJA";
    } else {
        cout << output;
    }
    cout << '\n';

    return 0;
}