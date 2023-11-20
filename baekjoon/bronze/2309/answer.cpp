#include <bits/stdc++.h>
using namespace std;

#define NUM     9
#define TOTAL   100


pair<int, int> solve(int sum, int* height)
{
    for (int i = 0; i < NUM; i++) {
        for (int j = i + 1; j < NUM; j++) {
            if ((sum - (height[i] + height[j])) == TOTAL) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main (void)
{
    int sum = 0;
    int height[NUM];
    pair<int, int> p;
    vector <int> answer;

    /* input */
    for (int i = 0; i < NUM; i++) {
        cin >> height[i];
        sum += height[i];
    }

    p = solve(sum, height);

    for (int i = 0; i < NUM; i++) {
        if (i == p.first || i == p.second) continue ;
        answer.push_back(height[i]);
    }

    /* print answer */
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
    
    return 0;
}