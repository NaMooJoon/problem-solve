#include<bits/stdc++.h>
using namespace std;
#define SIZE    8
#define MOD     1000

int N;
int arr[SIZE][SIZE];

void calculate(int coeffi) {

    if (coeffi == 1) {
        return ;
    }
    int half = coeffi / 2;
    calculate(half);
    
}

int main (void) {

    int B;

    cin >> N >> B; 
    calculate(B);

    return 0;
}