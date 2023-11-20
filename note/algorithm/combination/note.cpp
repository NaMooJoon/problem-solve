/*
* 여기 재귀함수는 외우는 것을 추천하였다.
*/
#include <bits/stdc++.h>
using namespace std;

int n = 5, k = 3;
int a[5] = {1, 2, 3, 4, 5};

void print(vector<int> &b)
{
    for (int i: b)
        cout << i << ' ';
    cout << '\n';
}


void combi(int start, vector<int> b) 
{
    if (b.size() == k) {
        print(b);
        return ;
    }
    for (int i = start + 1; i < n; i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main (void)
{
    vector<int> b;
    combi(-1, b);
    return 0;
}