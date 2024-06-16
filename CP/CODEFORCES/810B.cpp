#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, f, a, b;
    cin >> n >> f;

    vector<pair<ll, pll>> mx(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ll c = min(a, b);
        ll d = min(2 * a, b);
        mx[i] = make_pair(d - c, make_pair(c, d));
    }
    sort(mx.rbegin(), mx.rend());
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i < f ? mx[i].second.second : mx[i].second.first;
    }

    cout << sum;

    return 0;
}
