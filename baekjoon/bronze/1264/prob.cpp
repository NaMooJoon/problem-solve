#include <bits/stdc++.h>
using namespace std;

bool isSound (char ch) 
{
    bool flag = false;
    if (ch == 'a') {
        flag = true;
    }
    if (ch == 'e') {
        flag = true;
    }
    if (ch == 'i') {
        flag = true;
    }
    if (ch == 'o') {
        flag = true;
    }
    if (ch == 'u') {
        flag = true;
    }
    return flag;
}

int main (void)
{
    const int diff = 'a' - 'A';
    int count = 0;
    string s;
    cin.tie(nullptr); cout.tie(nullptr);

    while (true) 
    {
        count = 0;
        getline(cin, s);
        if (s == "#") {
            break;
        }
        for (char& ch : s) {
            if ('A' <= ch && ch <= 'Z') {
                ch += diff;
            }
            if (isSound(ch)) {
                count++;
            }
        }
        cout << count << '\n';
    }



    return 0;
}