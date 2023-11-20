/* 입력: string
    이 중에서 문자 하나씩 맵에 담으면서 숫자 counting
    - 문자의 개수가 홀수 인 문자가 하나보다 많을 경우 안됌.
    - 사전 순으로 문자를 꺼내면서 문자 출력
*/
#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    bool flag = false;
    string s, prefix, postfix, center;
    map<char, int> mp;

    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for (char ch : s) {
        mp[ch]++;
    }

    center  = "";
    prefix  = "";
    postfix = "";
    for (auto it : mp) {
        // cout << it.first << " : " << it.second << '\n';
        if (it.second & 1 == 0) {
            for (int i = 0; i < it.second; i += 2) {
                prefix  = prefix + it.first;
                postfix = it.first + postfix;
            }
        } else if (it.second & 1 == 1 && center == "") {
            for (int i = 0; i < it.second - 1; i += 2) {
                prefix  = prefix + it.first;
                postfix = it.first + postfix;
            }
            center += it.first;
        } else {
            flag = true;
        }
    }
    if (flag) {
        cout << "I'm Sorry Hansoo" << '\n';
        exit(0);
    }
    cout << prefix << center << postfix << '\n';

    return 0;
}