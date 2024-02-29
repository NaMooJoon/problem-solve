/* 순회강연 */
/**
 * {강연값, 날짜} 하루에 한 강연
 * 날짜 => 인덱스로, 날짜 별 강의료를 priority_queue로
 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE 10001

int N;
vector<int> vec[SIZE];

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int pay, d_day;
    for (int i = 0; i < N; i++) {
        cin >> pay >> d_day;
        vec[d_day].push_back(pay);
    }
}

void calculate() {
    int total = 0;
    priority_queue<int> pq;
    for (int i = SIZE - 1; i >= 1; i--) {
        for (int pay : vec[i]) {
            pq.push(pay);
        }
        if (pq.size()) {
            total += pq.top();
            pq.pop();
        }
    }

    cout << total << '\n';
}

int main(void) {
    inputInit();
    calculate();
    return 0;
}