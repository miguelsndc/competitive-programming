#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a[i] = b[i] = t;
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1], b[i] += b[i - 1];
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
            cout << a[r] - a[l - 1] << '\n';
        else
            cout << b[r] - b[l - 1] << '\n';
    }

    return 0;
}