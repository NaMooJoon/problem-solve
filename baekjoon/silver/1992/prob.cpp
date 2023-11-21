/* Quad Tree */
#include <bits/stdc++.h>
using namespace std;

#define SIZE        64

int checkScope(int(* scope)[SIZE], int y, int x, int size) 
{
    int result = scope[y][x];
    
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (scope[i][j] != result) {
                return -1;
            }
            result = scope[i][j];
        }
    }
    return result;
}

string convertToBit(int scopeType) 
{
    if (scopeType == 1) {
        return "1";
    }
    if (scopeType == 0) {
        return "0";
    }
    return "";
}

string quadTree(int(* picture)[SIZE], int y, int x, int size) 
{
    int scopeType;
    string result = "(";

    if (size == 1) {
        return convertToBit(picture[y][x]);
    }

    int quadSize = size / 2;

    /* Upper left side */
    if ((scopeType = checkScope(picture, y, x, quadSize)) == -1) {
        result += quadTree(picture, y, x, quadSize);
    }
    result += convertToBit(scopeType);

    /* Upper right side */
    if ((scopeType = checkScope(picture, y, x + quadSize, quadSize)) == -1) {
        result += quadTree(picture, y, x + quadSize, quadSize);
    }
    result += convertToBit(scopeType);

    /* Lower left side */
    if ((scopeType = checkScope(picture, y + quadSize, x, quadSize)) == -1) {
        result += quadTree(picture, y + quadSize, x, quadSize);
    }
    result += convertToBit(scopeType);

    /* Lower right side */
    if ((scopeType = checkScope(picture, y + quadSize, x + quadSize, quadSize)) == -1) {
        result += quadTree(picture, y + quadSize, x + quadSize, quadSize);
    }
    result += convertToBit(scopeType);

    result += ")";
    return result;
}

int main (void)
{
    int N;
    int picture[SIZE][SIZE];

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            picture[i][j] = (int) (s[j] - '0');
        }
    }

    string answer;
    if (checkScope(picture, 0, 0, N) == -1) {
        answer = quadTree(picture, 0, 0, N);
        cout << answer << '\n';
        return 0;
    }

    answer = convertToBit(checkScope(picture, 0, 0, N));
    cout << answer << '\n';

    return 0;
}