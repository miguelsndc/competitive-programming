#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    map<ll, int> lookup;
    for (int i = 0; i < q; i++) {
        char t;
        ll x;
        cin >> t >> x;
        if (t == 'a')
            lookup[x]++;
        else if (t == 't')
            lookup[x] = max(0, lookup[x] - 1);
        else
            cout << lookup[x] << '\n';
    }

    return 0;
}