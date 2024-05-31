#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    pair<int, int> l[n];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        l[i] = make_pair(t, i + 1);
    }
    sort(l, l + n);
    for (int i = 0; i < q; i++) {
        int x, qi;
        cin >> x >> qi;
        int k = lower_bound(l, l + n, x,
                            [](pair<int, int> a, const int b) {
                                return a.first < b;
                            }) -
                l;
        l;

        if (k + qi - 1 > n - 1 || l[k + qi - 1].first != x) {
            cout << -1 << '\n';
        } else {
            pair<int, int> j = l[k + qi - 1];
            cout << j.second << '\n';
        }
    }
    return 0;
}