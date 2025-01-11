#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<int> s;
    for (int i = 0; i < 4; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }
    cout << 4 - s.size();

}