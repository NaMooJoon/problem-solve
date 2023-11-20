#include <bits/stdc++.h>
using namespace std;

const char* whiteChar = " ";

void ltrim (string& s) 
{
    int pos = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            pos = i;
        } else {
            break;
        }
    }
    if (pos != -1) {
        s.erase(0, pos + 1);
    }
}

void rtrim (string& s)
{
    int pos = -1;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            pos = i;
        } else {
            break;
        }
    }
    if (pos != -1) {
        s.erase(pos);
    }
}

void trim (string& s)
{
    ltrim(s);
    rtrim(s);
}

int main (void)
{
    string s;
    int count;
    
    cin.tie(nullptr); cout.tie(nullptr);
    getline(cin, s);

    // trim string
    trim(s);
    if (s == "") {
        cout << "0" << '\n';
        exit(0);
    }
    
    count = 0;
    for (char ch : s) {
        if (ch == ' ') {
            count++;
        }
    }
    cout << count + 1 << '\n';

    return 0;
}