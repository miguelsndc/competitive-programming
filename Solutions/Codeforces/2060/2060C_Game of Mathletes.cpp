#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(begin(v), end(v));
    set<pair<int, int>> possible;
    for (int i = 0; i < n; i++) {
        int b = v[i];
        int lb = lower_bound(begin(v), end(v), k - b) - begin(v);
        if (lb < v.size()) {
            if (lb < i) swap(i, lb);
            possible.insert({i, lb});
        }
    } 
    cout << possible.size() << '\n';
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