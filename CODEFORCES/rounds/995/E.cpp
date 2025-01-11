#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> un;
    map<ll, ll> positive, negative;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        un.emplace_back(a);
        positive[a]++;
    }
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        un.emplace_back(b);
        negative[b]++;
    }

    sort(begin(un), end(un));

    ll best = 0;
    ll last = -1;
    ll neg = 0;
    for (ll p: un) {
        if (p == last) continue;
        last = p;
        ll curr = n * p;
        if (neg <= k) {
            best = max(curr, best);
        }
        neg += positive[p]; // add customers who will leave a negative review since best >= p
        neg -= negative[p]; // subtract customers who leave
        n -= negative[p]; // account for customers who leave
    }

    cout << best << '\n';
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