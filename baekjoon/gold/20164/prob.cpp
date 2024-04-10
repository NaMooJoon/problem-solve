#include <bits/stdc++.h>
using namespace std;

int N;
int g_min = 0, g_max = 0;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
}

vector<int> getCandidateNumbers(int num) {
    
    vector<int> ret;
    string s_num = to_string(num);

    for (int split1 = 1; split1 < s_num.length() - 1; split1++) {
        for (int split2 = split1 + 1; split2 < s_num.length(); split2++) {

            int num1 = stoi(s_num.substr(0, split1));
            int num2 = stoi(s_num.substr(split1, split2 - split1));
            int num3 = stoi(s_num.substr(split2, s_num.length() - split2));
            
            ret.push_back(num1 + num2 + num3);
        }
    }
    return ret;
}

inline int countOdd(int num) {
    int ret = 0;
    while (num > 0) {
        if (num & 1) { ret++; }
        num /= 10;
    }
    return ret;
}

int max_odd(int num) {

    int curr = countOdd(num);
    // 3 or more numbers 
    if (num / 100 >= 1) {
        vector<int> candidates = getCandidateNumbers(num);
        int max_count = 0;

        for (int i = 0; i < candidates.size(); i++) {
            int next_count = max_odd(candidates[i]);
            if (max_count < next_count) {
                max_count = next_count;
            }
        }
        return curr + max_count;
    } 
    // 2 numbers
    if (num / 10 >= 1) {
        return curr + max_odd(num / 10 + num % 10);
    }
    return curr;
}

int min_odd(int num) {
    
    int curr = countOdd(num);
    // 3 or more numbers 
    if (num / 100 >= 1) {
        vector<int> candidates = getCandidateNumbers(num);
        int min_count = INT_MAX;

        for (int i = 0; i < candidates.size(); i++) {
            int next_count = min_odd(candidates[i]);
            if (min_count > next_count) {
                min_count = next_count;
            }
        }
        return curr + min_count;
    } 
    // 2 numbers
    if (num / 10 >= 1) {
        return curr + min_odd(num / 10 + num % 10);
    }
    return curr;
}

void solve() {
    int _min = min_odd(N);
    int _max = max_odd(N);

    cout << _min << ' ' << _max << '\n';
}

int main(void) {
    inputInit();
    solve();
    return 0;
}