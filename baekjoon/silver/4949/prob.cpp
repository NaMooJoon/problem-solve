#include <bits/stdc++.h>
using namespace std;

bool isBalance(string s)
{
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '[') {
            st.push(ch);
        }
        if (ch == ')') {
            if (st.size() == 0 || st.top() != '(') {
                return false;
            }
            st.pop();
        }
        if (ch == ']') {
            if (st.size() == 0 || st.top() != '[') {
                return false;
            }
            st.pop();
        }
    }
    if (st.size()) {
        return false;
    }
    return true;
}

int main (void)
{
    const string DELIMITER_DOT = ".";
    string s;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (true) {
        getline(cin, s);
        if (s.compare(DELIMITER_DOT) == 0) { break; }
        
        string output = (isBalance(s))? "yes" : "no";
        cout << output << '\n';
    }

    return 0;
}