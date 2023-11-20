#include <bits/stdc++.h>
using namespace std;

#define NUM     9
#define SUM     100

int height[NUM] = {0};
vector<int> answer;

int calc (int d) {
    int sum = 0;
    for (int i = 0; i < d; i++) {
        sum += answer[i];
    }
    return sum;
}

void combi(int depth, int r) 
{
    static bool flag = false;

    if (flag) return ;
    if (answer.size() == r) {
        if (calc(r) == SUM) {
            for (int i = 0; i < r; i++) {
                cout << answer[i] << '\n';
            }
            flag = true;
        }
        return ;
    }
    for (int i = depth + 1; i < NUM; i++) {
        answer.push_back(height[i]);
        combi(i, r);
        answer.pop_back();
    }
}

int main (void)
{
    /* input */
    for (int i = 0; i < NUM; i++) {
        cin >> height[i];
    }
    /* sort */
    sort(height, height + NUM);
    /* combination */
    combi(-1, 7);

    return 0;
}

/* < BruteForce 문제 >
 * 난쟁이 키의 경우의 수를 모두 더함으로써 합이 100이 되는 것을 찾자.
 * => Combination
*/