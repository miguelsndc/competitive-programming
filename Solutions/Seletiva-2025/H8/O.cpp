#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second

const int maxn = 2e5 + 5;
vector<ll> bit(maxn);
void add(int pos, int val) {
	++pos; 
	while (pos <= maxn + 1) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

int query(int pos) {
	++pos;
	int sum = 0;
	while(pos > 0) {
		sum += bit[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    while(tc--) {
        int n,m;cin>>n>>m;
        vector<ll> v(n), ps(n + 1);
        rep(i, 0, n) cin >> v[i];
        rep(i, 0, n) ps[i + 1] = ps[i] + v[i];
        rep(i, 0, n) ps[i + 1] %= m;
        ll total = 0;
        for (int k = 1; k <= n; k++) {
            ll val = (k) *(ps[k]) - query(ps[k] + 1) * m;
        }
        cout << total;
    }
}