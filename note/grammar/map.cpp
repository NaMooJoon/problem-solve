#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string a[] = {"김준현", "김보배", "홍길동"};
int main (void) 
{
    for (int i = 0; i < 3; i++) {
        mp.insert({a[i], i + 1});
        mp[a[i]] = i + 1;
    }

    cout << mp["Joon"] << '\n';
    mp["Joon"] = 4;
    cout << "mp.size: " << mp.size() << '\n';
    mp.erase("Joon");
    auto it = mp.find("Joon");
    if (it == mp.end()) {
        cout << "못찾겠다 꾀꼬리 \n";
    }
    mp["Joon"] = 100;

    it = mp.find("Joon");
    if (it != mp.end()) {
        cout << (*it).first << " : " << (*it).second << '\n';
    }
    for (auto it : mp) {
        cout << (it).first << " : " << (it).second << '\n';
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " : " << (*it).second << '\n';
    }
    mp.clear();

    return 0;
}
