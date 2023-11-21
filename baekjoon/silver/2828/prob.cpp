/* 사과 담기 문제 */
#include <bits/stdc++.h>
using namespace std;

#define SIZE    10

int N, M;

int getDirectionToMove(int* basket, int apple)
{
    for (int i = apple; i < N; i++) {
        if (basket[i] == 1) {
            return -1;
        }
    }
    return 1;
}

void moveTo(int* basket, int dir)
{
    for (int i = 0; i < N; i++) {
        if (basket[i] == 1) {
            if (dir == 1) {
                basket[i] = 0;
                basket[i + M] = 1;
            } else {
                basket[i - 1] = 1;
                basket[i + M - 1] = 0;
            }
            break;
        }
    }
}

int moveBasket(int* basket, int apple) 
{
    int count = 0;

    int dir = getDirectionToMove(basket, apple);
    while (basket[apple] != 1) {
        moveTo(basket, dir);
        count++;
    }

    return count;
}

int main (void)
{
    int J;
    int basket[SIZE];
    int apple, count = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    fill(&basket[0], &basket[N-1], 0);
    for (int i = 0; i < M; i++) {
        basket[i] = 1;
    }


    cin >> J;
    for (int i = 0; i < J; i++) {
        cin >> apple;
        count += moveBasket(basket, apple - 1);
    }

    cout << count << '\n';


    return 0;
}