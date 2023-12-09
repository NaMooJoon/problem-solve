#include <bits/stdc++.h>
using namespace std;
#define WEIGHT_SIZE 100001
#define COUNT_SIZE  101

int value[WEIGHT_SIZE][COUNT_SIZE];

int main(void)
{
    int N, K;
    int w, v;
    vector<pair<int,int>> weightAndValue;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        weightAndValue.push_back({w, v});
    }

    sort(weightAndValue.begin(), weightAndValue.end());

    for (int i = 0; i < weightAndValue.size(); i++) {
        value[0][i] = 0;
    }
    for (int weight = 0; weight <= K; weight++) {
        value[weight][0] = 0;

        for (int i = 0; i < weightAndValue.size(); i++) {
            int idx = i + 1;
            int before = weight - weightAndValue[i].first;
            if (before < 0) {
                value[weight][idx] = value[weight][idx-1];
                continue;
            }
            int result = max(value[before][idx-1] + weightAndValue[i].second, value[weight][idx-1]);
            value[weight][idx] = result;
        }
    }

    cout << value[K][weightAndValue.size()] << '\n';

    return 0;
}