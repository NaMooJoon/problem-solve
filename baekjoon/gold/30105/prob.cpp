#include <bits/stdc++.h>
using namespace std;

bool pos[1000000001] = {false};


int main (void)
{
    int N;
    int *x;
    int leftX, rightX;
    bool flag;
    vector<int> answer;

    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    x = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        pos[x[i]] = true;
    }

    for (int dist = 1; dist <= x[N-1] - x[0]; dist++) {
        flag = true;
        for (int i = 0; i < N; i++) {
            leftX   = x[i] - dist;
            rightX  = x[i] + dist;
            if ((leftX < 0 || pos[leftX] == false)
             && (rightX > x[N - 1] || pos[rightX] == false)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            answer.push_back(dist);
        }
    }
    
    if (answer.size()) {
        cout << answer.size() << '\n';
        for (int dist : answer) {
            cout<< dist << ' ';
        }
        cout << '\n';    
    } else {
        cout << "0" << '\n';
    }
    


    return 0; 
}