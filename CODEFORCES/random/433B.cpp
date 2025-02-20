#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t, q, l, r;
    cin >> n;
    vll psum(n + 1);
    vll psumsort(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t;
        psum[i] = psumsort[i] = t;
    }
    sort(psumsort.begin(), psumsort.end());
    for (int i = 1; i <= n; i++) {
        psum[i] += psum[i - 1];
        psumsort[i] += psumsort[i - 1];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> t >> l >> r;
        if (t == 1) {
            cout << psum[r] - psum[l - 1] << '\n';
        } else {
            cout << psumsort[r] - psumsort[l - 1] << "\n";
        }
    }

    return 0;
}