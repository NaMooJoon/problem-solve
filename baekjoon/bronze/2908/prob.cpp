#include <bits/stdc++.h>
using namespace std;

void reverse (string& s) {
    int len = s.size();
    for (int i = 0; i < (len / 2); i++) {
        swap(s[i], s[len - (i + 1)]);
    }
}

int main (void)
{
    string a, b;
    int num1, num2;

    cin.tie(nullptr); cout.tie(nullptr);

    cin >> a >> b;

    reverse(a);
    reverse(b);

    num1 = atoi(a.c_str());
    num2 = atoi(b.c_str());

    cout << max(num1, num2) << '\n';

    return 0;
}