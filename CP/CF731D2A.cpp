#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    int p = 0;
    int moves = 0;
    for (char &i: s) {
        int m = i - 97;
        int walk = abs(p - m);
        moves += walk <= (26 - walk) ? walk : (26 - walk);
        p = m;
    }
    cout << moves;

    return 0;
}