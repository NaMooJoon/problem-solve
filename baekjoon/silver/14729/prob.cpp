#include<bits/stdc++.h>
using namespace std;

priority_queue<float, vector<float>, greater<float>> pq;
void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    float grade;
    while (N--) {
        cin >> grade;
        pq.push(grade);
    }
}

void printResult() {
    cout << fixed;
    cout.precision(3);
    for (int i = 0; i < 7; i++) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}

int main(void) {

    inputInit();
    printResult();
    return 0;
}