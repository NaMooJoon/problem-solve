#include <bits/stdc++.h>
using namespace std;

#define ROT         13
#define NUM_CHAR    26

int main (void) 
{
    string s, out = "";
    getline(cin, s);

    for (char ch : s) {
        if ('a' <= ch && ch <= 'z') {
            ch += ((ch + ROT) > 'z')? (ROT - NUM_CHAR)
                                    : (ROT)
                                    ;
        }
        if ('A' <= ch && ch <= 'Z') {
            ch += ((ch + ROT) > 'Z')? (ROT - NUM_CHAR)
                                    : (ROT)
                                    ;
        }
        out += ch;
    }
    cout << out << '\n';

    return 0;
}