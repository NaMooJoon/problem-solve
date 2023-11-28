#include <bits/stdc++.h>
using namespace std;

const char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
string sound = "aeiou";

void printMessage(string password, bool isAcceptable) 
{
    if (isAcceptable) {
        cout << "<" << password << ">" << " is acceptable.\n";
        return;
    }
    cout << "<" << password << ">" << " is not acceptable.\n";
}

bool isVowel(char ch)
{
    for (char sound : vowel) {
        if (ch == sound) {
            return true;
        }
    }
    return false;
}

bool checkIncludingVowel(string password)
{
    for (char ch : password) {
        if (isVowel(ch)) {
            return true;
        }
    }
    return false;
}

bool checkConsecutiveVowel(string password)
{
    int count = 1;
    bool IsPrevVowel = isVowel(password[0]);
    for (int i = 1; i < password.size(); i++) {
        bool isCurrVowel = isVowel(password[i]);

        if (isCurrVowel) {
            count = (IsPrevVowel)? count + 1 : 1;
        } else {
            count = (!IsPrevVowel)? count + 1 : 1;
        }
        IsPrevVowel = isCurrVowel;

        if (count >= 3) {
            return false;
        }
    }
    return true;
}

bool checkConsecutive(string password)
{
    char prevChar = '*';
    for (char ch : password) {
        if (prevChar == ch) {
            if (ch == 'e' || ch == 'o') {
                continue;
            }
            return false;
        }
        prevChar = ch;
    }
    return true;
}

bool solve(string password) 
{
    if (!checkIncludingVowel(password)) {
        return false;
    }
    if (!checkConsecutiveVowel(password)) {
        return false;
    }
    if (!checkConsecutive(password)) {
        return false;
    }
    return true;
}

int main (void)
{
    const string END = "end";
    string password;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while ((cin >> password)) {
        if (password.compare(END) == 0) {
            break;
        }
        printMessage(password, solve(password));
    }

    return 0;
}