#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE    50
#define BOARD_SIZE  8

int getPaintCount (bool board[][MAX_SIZE], int x, int y)
{
    int retCount = 0;
    bool nextColor;

    nextColor = board[x][y];

    for (int i = x; i < x + BOARD_SIZE; i++) {
        for (int j = y; j < y + BOARD_SIZE; j++) {
            if (board[i][j] != nextColor) {
                retCount++;
            }
            nextColor = !nextColor;
        }
        nextColor = !nextColor;
    }

    return retCount;
}

int getMinPaintCount (bool board[][MAX_SIZE], int x, int y)
{
    int case1, case2;

    board[x][y] = !board[x][y];
    case1 = getPaintCount(board, x, y) + 1;

    board[x][y] = !board[x][y];
    case2 = getPaintCount(board, x, y);

    return min(case1, case2);
}

int main (void)
{
    int min = INT32_MAX;
    int M, N;
    int paint;
    char color;
    bool board[MAX_SIZE][MAX_SIZE];

    cin.tie(nullptr); cout.tie(nullptr);
    cin >> M >> N;
    /* read */
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> color;
            board[i][j] = (color == 'W')? false : true;
        }
    }

    for (int i = 0; i < M - BOARD_SIZE + 1; i++) {
        for (int j = 0; j < N - BOARD_SIZE + 1; j++) {
            paint = getMinPaintCount(board, i, j);
            if (min > paint) {
                min = paint;
            }
        }
    }

    cout << min << '\n';


    return 0;
}