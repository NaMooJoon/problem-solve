#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int N, count = 0;
    char prev;
    bool flag;
    string s;
    map<char,int> mp;

    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    while (N--)
    {
        /* init */
        flag = true;
        mp.clear();

        /* input */
        cin >> s;
        prev = s[0];
        
        /* solve */
        for (char ch : s) {
            if (mp[ch] != 0 && ch != prev) {
                flag = false;
                break;
            }
            mp[ch]++;
            prev = ch;
        }
        if (flag) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}