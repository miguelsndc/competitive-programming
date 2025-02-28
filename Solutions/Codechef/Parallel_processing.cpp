#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

/*
    find a spot where the running time for left and right
    are minimized, max(l,r) is minimized
*/

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (ll &x: v) cin >> x;
    vector<ll> ps(n + 1);
    ps[0] = 0;
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + v[i];
    }
    ll mx = 1e18;
    for (int i = 0; i < n; i++) {
        ll v = max(ps[i], ps[n] - ps[i]);
        mx = min(mx, v);
    }
        
        
    cout << mx << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}