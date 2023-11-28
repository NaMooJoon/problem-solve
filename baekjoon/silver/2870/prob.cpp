#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2) 
{
    if (s1.length() < s2.length()) {
        return true;
    } else if (s1.length() > s2.length()) {
        return false;
    }
    return (s1.compare(s2) < 0);
}

inline bool isNumber(char ch)
{
    return ('0' <= ch && ch <= '9');
}

vector<string> parse(string s) 
{
    vector<string> ret;
    int idx;
    for (idx = 0; idx < s.size(); idx++) {
        if (isNumber(s[idx])) {
            break;
        }
    }

    if (idx == s.size()) {
        return ret;
    }
    
    int start = idx;
    int len = 1;
    for (idx = start + 1; idx < s.size(); idx++) {
        if (s[start] == '0') {
            if (!isNumber(s[idx])) {
                for (string number : parse(s.substr(start + len))) {
                    ret.push_back(number);
                }
                break;
            }
            start = idx;
            continue;
        } 
        if (isNumber(s[idx])){
            len++;
        }
        else {
            for (string number : parse(s.substr(start + len))) {
                ret.push_back(number);
            }
            break;
        }
    }

    ret.push_back(s.substr(start, len));
    return ret;
}

int main (void)
{
    vector<string> numbers;
    int N;
    string s;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int test = 0; test < N; test++) {
        cin >> s;
        for (string number : parse(s)) {
            numbers.push_back(number);
        }
    }
    sort(numbers.begin(), numbers.end(), comp);
    for (string s : numbers) {
        cout << s << '\n';
    }

    return 0;
}