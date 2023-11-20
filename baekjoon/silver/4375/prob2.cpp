#include <bits/stdc++.h>
using namespace std;

int solve (int n) 
{
    int count = 1;
    long long m = 1;

    while (m % n != 0) {
        count++;
        m = (m * 10 + 1) % n;
    }

    return count;
}

int main (void)
{
    int num;
    string s;

    cin.tie(NULL); cout.tie(NULL);

    while (scanf("%d", &num) != EOF) {
        printf("%d\n", solve(num));
    }

    return 0;
}