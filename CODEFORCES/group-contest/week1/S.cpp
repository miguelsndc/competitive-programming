#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

bool ok(int n, int diff) {
    ll ans = n * 1LL *  (n + 1) / 2;
    if (ans < diff) return false;
    return ans % 2 == diff % 2;
}

void solve() {
    int  a, b; cin >> a >> b;
    int d = abs(a - b);
    int k = 1;

    if (d == 0) {
        cout << 0 << '\n';
        return;
    }
    while(!ok(k, d)) ++k;
    cout << k << '\n'; 
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
         solve();
    }
}