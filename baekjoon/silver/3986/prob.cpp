#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int n, count = 0;
    string s;
    stack<char> st;

    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while (n--) {
        
        cin >> s;
        
        for (char ch : s) {
            if (st.empty()) {
                st.push(ch);
            } else if (st.top() == ch) {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        /* count */
        if (st.empty()) {
            count++;
        } 
        /* flush */
        while (!st.empty()) {
            st.pop();
        }

    }
    cout << count << '\n';
    
    return 0;
}