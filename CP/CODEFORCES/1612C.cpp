#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "
// we have a total of y^2 texts
// if y^2 <= x we can write the whole thing
// we need to check if the total messages we sent is >= x
// find the minimum such that the above predicate is true
// we can define our search space as [1, 2k - 1]
// our function f(message) tells the number for the specified message

// 1 to 2k-1 sums to k^2
ll fn(ll mid) {
    return mid * (mid + 1) / 2;
}

void solve() {
    ll k, x;
    cin >> k >> x;
    ll lo = 1, hi = 2 * k - 1, ans = 2 * k - 1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        bool done;
        if (mid >= k) {
            done = (fn(k) + fn(k - 1) - fn(2 * k - 1 - mid)) >= x;
        } else {
            done = fn(mid) >= x;
        }

        if (done) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}