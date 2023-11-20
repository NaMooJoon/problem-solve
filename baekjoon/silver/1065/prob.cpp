#include <bits/stdc++.h>
using namespace std;

int getDecimalPoint(int N) 
{
    int count = 0;
    while (N != 0) {
        count++;
        N = N / 10;
    }
    return count;
}

bool isTrue(int N)
{
    bool flag = true;
    int decimal[4];
    int point = getDecimalPoint(N);
    int far;


    for (int i = 0; i < point; i++) {
        decimal[i] = N % 10;
        N = N / 10;
    }

    if (point <= 2) {
        flag = true;
    } else {
        far = decimal[1] - decimal[0];
        for (int i = 2; i < point; i++) {
            if (far != (decimal[i] - decimal[i - 1])) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main (void)
{
    int N;
    int count = 0;
    
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int num = 1; num <= N; num++) {
        if (isTrue(num)) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}