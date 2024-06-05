#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(ll y) {
    return y * (y + 1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t, k, x;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> k >> x;
        ll l = 1, r = 2 * k - 1;
        ll ans = 2 * k - 1;
        int done = false;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid >= k) {  // second half up to mid
                done = (f(k) + f(k - 1) - f(2 * k - 1 - mid)) >= x;
            } else {
                done = f(mid) >= x;  // first half
            }
            if (done) {  // we got a valid solution, however we keep iterating till the smallest one is found.
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}