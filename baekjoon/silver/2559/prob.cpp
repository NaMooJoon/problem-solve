#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main (void)
{
    int N, K, temp;
    int temper[MAX];
    int max = 0;

    /* read input */
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> temper[i];
    }
    /* initialize max */
    for (int i = 0; i < K; i++) {
        max += temper[i];
    }
    /* solve */
    temp = max;
    for (int i = K; i < N; i++) {
        temp = temp + (temper[i] - temper[i - K]);
        if (max < temp) {
            max = temp;
        }
    }    
    /* result */
    cout << max << '\n';

    return 0;
}