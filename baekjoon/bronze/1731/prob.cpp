#include <bits/stdc++.h>
using namespace std;

#define MAX     50
enum type { ADD, MUL, N_TYPE };

int val;
enum type getType(int* arr) 
{
    if ((arr[1] - arr[0]) == (arr[2] - arr[1])) {
        val = arr[1] - arr[0];
        return ADD;
    } else {
        val = arr[1] / arr[0];
        return MUL;
    }
    return N_TYPE;
}

int main (void)
{
    int N;
    int arr[MAX+1];

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    switch (getType(arr))
    {
    case ADD:
        arr[N] = arr[N-1] + val;
        break;

    case MUL:
        arr[N] = arr[N-1] * val;
        break;

    default:
        break;
    }
    cout << arr[N] << '\n';

    return 0;   
}