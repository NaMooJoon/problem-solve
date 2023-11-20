#include <bits/stdc++.h>
using namespace std;

void printList(vector<int> v) 
{
    for (int n : v) {
        cout << n << ' ';
    }
    cout << '\n';
}

int main (void)
{
    int N, L;
    int split, sum;
    bool flag;
    vector<int> v;

    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> L;

    while (true)
    {
        v.clear();
        flag = false;
        split = N / L - (L - 1);

        if (split < 0) {
            split = 0;
        }

        if (L > 100) {
            cout << "-1" << '\n';
            break;
        }

        for (int i = 0; i < L; i++) {
            v.push_back(split++);
        }
        while (true) {
            sum = accumulate(v.begin(), v.end(), 0);
            if (N == sum) {
                flag = true;
                break;
            } 
            else if (N < sum) {
                break;
            } 
            else {
                for (int i = 0; i < v.size(); i++) {
                    v[i]++;
                }
            }
        }
        if (flag) {
            printList(v);
            break;
        }
        L++;
    }

    return 0;
}
