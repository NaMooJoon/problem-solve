#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int N;
    int time = 0;
    int flyingBird = 1;

    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    while (true) 
    {
        time++;
        if (N == flyingBird) {
            break;
        }
        if (N < flyingBird) {
            flyingBird = 1;
            time--;
            continue;
        }
        N -= flyingBird++;
    }
    cout << time << '\n';

    return 0;
}