#include <bits/stdc++.h>
using namespace std;

int solve(int current, int target) {

    if (current == target) {
        return 1;
    }

    int half = current / 2;
    if (half > target) {
        return solve(half, target);
    }
    if (half < target) {
        return 1 + solve(half, target - half);
    }
    return 1;
}

int main(void) {
    int stick = 64;
    int X;
    cin >> X;
    cout << solve(stick, X) << '\n';

    return 0;
}