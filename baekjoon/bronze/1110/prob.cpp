#include <bits/stdc++.h>
using namespace std;

inline int cycle(int num) {

    int sum = (num / 10) + (num % 10);
    int newNum = (num % 10) * 10 + (sum % 10);

    return newNum;
}

int main(void) {
    int N;
    cin >> N;

    int num = N;
    int count = 0;
    while (true) {
        count++;
        num = cycle(num);
        if (num == N) break;
    }

    cout << count << '\n';

    return 0;
}