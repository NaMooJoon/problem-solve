#include <bits/stdc++.h>
using namespace std;
#define SIZE 2000000001

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    while (N--) {
        int x, y;
        cin >> x >> y;
        pq.push({x, y});
    }
}


void printAnswer() {
    int answer = 0;

    int begin = pq.top().first;
    int end = pq.top().second; pq.pop();
    while (pq.size()) {
        int new_begin = pq.top().first;
        int new_end = pq.top().second;

        if (end < new_begin) {
            answer += end - begin;
            begin = new_begin;
            end = new_end;
        } 
        else if (new_begin <= end && end < new_end) {
            end = new_end;
        }
        pq.pop();
    }
    answer += end - begin;
    cout << answer << '\n';
}


int main(void) {
    inputInit();
    printAnswer();

    return 0;
}