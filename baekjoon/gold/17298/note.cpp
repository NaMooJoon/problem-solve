/* 오큰수 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000001

/**
 * @brief 
 * Stack을 활용해서 풀어야하는 문제.
 * 오큰수가 아닌 경우는 스택에 담아두다가,
 * 오큰수를 만나면 스택에 담긴 숫자들을 오큰수로 채우기.
 * 4
 * 3 2 1 4
 * 4 4 4 -1
 */

int main (void) {
    int N;
    int arr[SIZE], nge[SIZE];
    stack<int> st;

    cin >> N;
    memset(nge, -1, sizeof(nge));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        while (st.size() && arr[st.top()] < arr[i]) {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << nge[i] << ' ';
    }
    cout << '\n';

    return 0;
}