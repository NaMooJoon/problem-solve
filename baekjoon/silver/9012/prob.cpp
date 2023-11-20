#include <bits/stdc++.h>
using namespace std;

void solve (string s) 
{
    stack<char> st;
    for (char ch : s) {
        if (ch == '(') {
            st.push('(');
        }
        if (ch == ')') {
            if (st.empty()) {
                cout << "NO" << '\n';
                return ;
            }
            st.pop();
        }
    }
    if (st.empty()) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main (void)
{
    int T;
    string s;
    
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s;
        solve(s);
    }
    
    return 0;
}