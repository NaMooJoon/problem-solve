#include <bits/stdc++.h>
using namespace std;

char toChar(int num) {
    if (num < 10) {
        return (char)('0' + num);
    }
    num -= 10;
    return (char)('A' + num);
}

string solve(int N, int B) {
    string ret = "";
    while (N / B > 0) {
        ret = toChar(N % B) + ret;
        N = N / B;
    }
    ret = toChar(N) + ret;
    return ret;
}

int main (void) {

    int N, B;
    cin >> N >> B;

    cout << solve(N, B) << '\n';

    return 0;
}