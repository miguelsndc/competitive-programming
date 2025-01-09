#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

ll less_than_x(vector<ll> &s, ll x, ll sum) {
    ll ans = 0;
    int n = s.size();

    for (int i = n - 1, j = 0; i >= 0; i--) {
        while(j < n && sum - s[i] - s[j] >= x) {
            j++;
        }
        ans += (n - j);
    }

    for (int i = 0; i < n; i++) {
        if (sum - s[i] - s[i] < x) {
            --ans;
        }
    }

    return ans / 2;
}

void solve() {
    int n; ll x, y; cin >> n >> x >> y;
    vector<ll> s(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) { 
        cin >> s[i]; 
        sum += s[i];
    }

    sort(begin(s), end(s));

    ll ltx = less_than_x(s, x, sum);
    ll lty = less_than_x(s, y + 1, sum);

    cout << lty - ltx << '\n';
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