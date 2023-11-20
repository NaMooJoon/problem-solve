#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(int num) 
{
    bool retValue = true;
    int len;
    vector<int> v;
    while (num > 0) 
    {
        v.push_back(num % 10);
        num = num / 10;
    }
    len = v.size();
    for (int i = 0; i < len / 2; i++) {
        if (v[i] != v[len - (i + 1)]) {
            retValue = false;
            break;
        }
    }
    return retValue;
}

int main (void)
{
    int N;
    int MAX_NUM;
    bool* prime;

    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    MAX_NUM = N * 50;

    prime = new bool[MAX_NUM];

    fill_n(prime, MAX_NUM, true);
    prime[1] = false;
    for (int i = 2; i < MAX_NUM / 2 + 1; i++) {
        if (prime[i]) {
            for (int j = i + i; j < MAX_NUM; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = N; i < MAX_NUM; i++) {
        if (prime[i] && isPalindrom(i)) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}