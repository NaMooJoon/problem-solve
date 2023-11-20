#include <bits/stdc++.h>
using namespace std;

int main (void) 
{
    int N, i;
    string pattern;
    string prefix, postfix;
    string* filename;

    cin >> N;
    cin >> pattern;

    i = pattern.find('*');
    prefix  = pattern.substr(0, i);
    postfix = pattern.substr(i + 1, pattern.length());

    filename = new string[N];

    for (i = 0; i < N; i++) {
        cin >> filename[i];
    }

    for (i = 0; i < N; i++) {
        if (filename[i].length() < prefix.length() + postfix.length()) {
            cout << "NE" << '\n';
        } else if (filename[i].substr(0, prefix.length()) != prefix) {
            cout << "NE" << '\n';
        } else if (filename[i].substr(filename[i].length() - postfix.length(), filename[i].length()) != postfix) {
            cout << "NE" << '\n';
        } else {
            cout << "DA" << '\n';
        }
    }

    return 0;
}