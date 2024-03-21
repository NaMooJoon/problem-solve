#include <bits/stdc++.h>
using namespace std;

string aLine;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    getline(cin, aLine, '\n');
}


int main(void) {
    bool isTag = false;
    string answer = "";
    string word = "";
    
    inputInit();
    
    for (char ch : aLine) {
        if (isTag && ch != '>') {
            answer.push_back(ch);
            continue;
        }
        if (ch == '<') {
            isTag = true;
            reverse(word.begin(), word.end());
            answer += word + '<';
            word = "";
            continue;
        }
        if (ch == '>') {
            isTag = false;
            answer.push_back(ch);
            continue;
        }
        if (ch == ' ') {
            reverse(word.begin(), word.end());
            answer += word + ' ';
            word = "";
            continue;
        }
        if (!isTag) {
            word.push_back(ch);
        }
    }
    reverse(word.begin(), word.end());
    answer += word;

    cout << answer << '\n';
    return 0;
}