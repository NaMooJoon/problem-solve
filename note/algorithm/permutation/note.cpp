#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void printV(vector<int> &v)
{
    for (int i = 0; i < 3; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void makePermutation(int n, int r, int depth)
{
    // cout << n << " : " << r << " : " << depth << '\n'; 
    if (r == depth) {
        printV(v);
        return ;
    }
    for (int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
}

int main (void)
{    
    clock_t start, end;
    for (int i = 1; i <= 10; i++) {
        v.push_back(i);
    }
    start = time(NULL);
    makePermutation(10, 3, 0);
    end = time(NULL);

    cout << "Time: " << (double) (end - start);

    return 0;
}