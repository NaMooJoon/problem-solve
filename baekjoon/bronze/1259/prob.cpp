#include <bits/stdc++.h>
using namespace std;

void solve (string s) 
{
    bool isPalindrom = true;
    int last = s.size() - 1;
    int idx = ((s.size() % 2) & 1)? s.size() / 2 - 1
                                  : s.size() / 2
                                  ;
    for (int i = idx; i >= 0; i--) {
        if (s[i] != s[last - i]) {
            isPalindrom = false;
            break;
        }
    }
    
    if (isPalindrom) {
        cout << "yes" << '\n';
    } else {
        cout << "no" << '\n';
    }

}

int main (void)
{
    string num;
    cin.tie(nullptr); cout.tie(nullptr);

    while (true)
    {
        cin >> num;
        if (num == "0") {
            break;
        }
        solve(num);
    }


    return 0;
}