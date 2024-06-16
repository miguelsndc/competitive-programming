#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    getline(cin, s);
    getline(cin, t);
    
    int p = 1;
    for (int i = 0; i < t.size(); i++) {
        if (s[p - 1] == t[i]) {
            p++;
        }
    }

    cout << p;
    return 0;
}