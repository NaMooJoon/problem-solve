#include <bits/stdc++.h>
using namespace std;

typedef enum _command {
    ADD,
    REMOVE,
    CHECK,
    TOGGLE,
    ALL,
    EMPTY,
    N_command,
} Command ;

string command_str[N_command] = {
    "add",
    "remove",
    "check",
    "toggle",
    "all",
    "empty"
};

int N;

Command getCommand(string s) {
    for (int i = 0; i < N_command; i++) {
        if (s.compare(command_str[i]) == 0) {
            return (Command) i;
        }
    }
    return N_command;
}

void inputInit() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
}

void solve() {
    int set = 0;

    string str;
    int num;
    bool bit;
    for (int i = 0; i < N; i++) {
        cin >> str;
        switch (getCommand(str)) {
            case ADD :
                cin >> num;
                set |= (1 << num);
                break;
            case REMOVE:
                cin >> num;
                set &= (-1 xor (1 << num));
                break;
            case CHECK :
                cin >> num;
                bit = set & (1 << num);
                cout << (int) bit << '\n';
                break;
            case TOGGLE :
                cin >> num;
                if (set & (1 << num)) {
                    set &= (-1 xor (1 << num));
                } else {
                    set |= (1 << num); 
                }
                break;
            case ALL:
                for (int i = 1; i <= 20; i++) {
                    set |= (1 << i);
                }
                break;
            case EMPTY:
                set = 0;
                break;
            default:
                break;
        }
    }
}

int main(void) {
    inputInit();
    solve();
    return 0;
}
