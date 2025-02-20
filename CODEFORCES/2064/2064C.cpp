#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int power(int b, int p, int m) {
    long long x = 1;
    int power = b % m;
    int k = log2(p);
    for (int i = 0; i <= k; i++) {
       int a = (p >> i) & 1;
       if (a == 1)
           x = (x * power) % m;
       power = (power * power) % m;
   }
    return x;
}

void solve() {
    int n; cin >> n;
    vector<ll> v(n), pre(n), suf(n);

    for (ll &x:v) cin>>x;
    
    if (v[0] > 0) pre[0] = v[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1];
        if (v[i] > 0) {
            pre[i] += v[i];
        }
    }
    if(v[n - 1] < 0) suf[n - 1] = -v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1];
        if (v[i] < 0) {
            suf[i] -= v[i];
        }
    }

    ll mx= 0;
    for (int i =0; i < n; i++) {
        mx = max(mx, pre[i] + suf[i]);
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