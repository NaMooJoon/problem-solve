#include <bits/stdc++.h>
using namespace std;

int score[3] = {0, 0, 0};
int winningTime[3] = {0, 0, 0};

void timeCheck(int prev, int next)
{
    if (score[1] > score[2]) {
        winningTime[1] += next - prev;
    } else if (score[1] < score[2]) {
        winningTime[2] += next - prev;
    }
}

int calculateInteval(int h, int m) 
{
    return (h * 60 + m);
}

string timeFormat(int time)
{
    char timeStr[8];
    int hour = time / 60;
    int minutes = time % 60;

    snprintf(timeStr, sizeof(timeStr), "%02d:%02d", hour, minutes);
    return string(timeStr);
}

int main (void)
{
    int N;
    string s;
    int team, hour, minute;
    int prevTime = 0;

    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        sscanf(s.c_str(), "%d %d:%d", &team, &hour, &minute);

        int newTime = calculateInteval(hour, minute);

        timeCheck(prevTime, newTime);

        score[team]++;
        prevTime = newTime;
    }
    if (score[1] != score[2]) {
        timeCheck(prevTime, 2880);
    }

    cout << timeFormat(winningTime[1]) << '\n';
    cout << timeFormat(winningTime[2]) << '\n';

    return 0;
}