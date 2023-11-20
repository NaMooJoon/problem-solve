#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN     1000

int main (void)
{
    int N;
    int arr[MAX_LEN] = {0};
    int dp[MAX_LEN] = {0};
    int prevIdx, maxIdx;
    bool isFirst;
    vector<int>* vPtr[MAX_LEN] = {nullptr};

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vPtr[0] = new vector<int>;
    vPtr[0]->push_back(arr[0]);

    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        isFirst = true;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i] && (dp[j] + 1) > dp[i]) {
                dp[i] = dp[j] + 1;
                prevIdx = j;
                isFirst = false;
            }

            vPtr[i] = new vector<int>;
            if (isFirst) {
                dp[i] = 1;
                vPtr[i]->push_back(arr[i]);
            } else {
                vPtr[i]->resize(vPtr[prevIdx]->size());
                copy(vPtr[prevIdx]->begin(), vPtr[prevIdx]->end(), vPtr[i]->begin());
                vPtr[i]->push_back(arr[i]);
            }

        }
    }

    maxIdx = 0;
    for (int i = 1; i < N; i++) {
        if (dp[maxIdx] < dp[i]) {
            maxIdx = i;
        }
    }
    cout << dp[maxIdx] << '\n';
    for (int i : *(vPtr[maxIdx])) {
        cout << i << ' ';
    }
    cout << '\n';

    for (int i = 0; i < N; i++) {
        if (vPtr[i] != nullptr) {
            delete vPtr[i];
        }
    }

    return 0;  
}


