#include <bits/stdc++.h>
using namespace std;

string ret;
vector<string> v;

void go() {
    while (ret.size() && ret.front() == '0') {
        ret.erase(ret.begin());
    }
    v.push_back(ret);
    ret = "";
}

int main (void)
{
    int N;
    string s;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s;
        ret = "";
        for (int j = 0; j < s.size(); j++) {
            if ('0' <= s[j] && s[j] <= '9') {
                ret += s[j];
            } else if (ret.size()) {
                go();
            }
        }
        if (ret.size()) {
            go();
        }
    }

    for (string s : v) {
        cout << s << '\n';
    }
    return 0;
}