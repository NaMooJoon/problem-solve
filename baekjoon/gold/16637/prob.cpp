/* 16637번, 괄호 추가하기 */
/* 바로 더할지, 뒤에 식 계산하고 더할지 */
#include <bits/stdc++.h>
using namespace std;

int answer = -INT_MAX;

int compute(int a, char op, int b) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    default:
        return 0;
    }
}

void calculate(int prev, string expression, int numOfOperator) {

    int operand, direct, post;

    if (numOfOperator == 0) {
        answer = max(answer, prev);
        return;
    }

    operand = expression[1] - '0'; // if a + b, it's b
    direct = compute(prev, expression[0], operand);

    operand = compute(expression[1] - '0', expression[2], expression[3] - '0'); // if a + b + c, b + c
    post = compute(prev, expression[0], operand);

    calculate(direct, expression.substr(2, expression.size() - 2), numOfOperator - 1);
    if (numOfOperator >= 2) {
        calculate(post, expression.substr(4, expression.size() - 4), numOfOperator - 2);
    }
}

int main (void)
{
    int N;
    string s;

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> s;

    int prev = s[0] - '0';
    calculate(prev, s.substr(1, N - 1), N / 2);

    cout << answer << '\n';

    return 0;
}