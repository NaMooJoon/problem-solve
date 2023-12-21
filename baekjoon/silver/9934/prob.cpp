#include <bits/stdc++.h>
using namespace std;
#define SIZE    2048

int arr[SIZE];

void printAnswer(int begin, int end) {

    int count = 0;
    int newLineCount = 1;

    queue<int> q;
    q.push(begin * 10000 + end);

    while (q.size()) {

        if (q.front() < 0) { continue; }

        int begin = q.front() / 10000;
        int end = q.front() % 10000;
        q.pop();

        int mid = (begin + end) / 2;
        cout << arr[mid] << ' ';
        count++;

        if (count == newLineCount) {
            cout << '\n';
            count = 0;
            newLineCount *= 2;
        }
        if (begin + 1 == end) {
            continue;
        }
        q.push(begin * 10000 + mid);
        q.push((mid + 1) * 10000 + end);
    }
}

int main (void) {

    int depth; 

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> depth;
    
    int size = (int) pow(2, depth) - 1;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    printAnswer(0, size);

    return 0;
}