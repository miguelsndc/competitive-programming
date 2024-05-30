#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll customers[m];
    multiset<ll> tickets;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        tickets.insert(t);
    }
    for (int j = 0; j < m; j++) cin >> customers[j];

    for (int i = 0; i < m; i++) {
        auto it = tickets.upper_bound(customers[i]);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            it--;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }

    return 0;
}