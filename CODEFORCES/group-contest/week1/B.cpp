#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(begin(a), end(a));
        ll ans = 0;
        for (int l = 0; l < n; l++) {
            ll p = upper_bound(begin(a), end(a), a[l] + 2) - begin(a);
            --p;
            if (p - l >= 1) { 
                ans += ((p - l - 1) * (p - l)) / 2;
            }
        }
        cout << ans << '\n';
    }
}