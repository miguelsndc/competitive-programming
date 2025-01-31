#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

const int MAXN = 1e5;
vector<int> g[MAXN];

void solve() {
    int n, m; cin >> n >> m;
    vector<int> g[MAXN];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map<int, int> r;
    for (int i = 0; i < n; i++) {
        int reachable = g[i].size();
        r[reachable]++;
    }

    if (r[2] == n) {
        cout << "ring topology";
    } else if (r[n - 1] == 1 && r[1] == n - 1) {
        cout << "star topology";
    } else if (r[1] == 2 && r[2] == n - 2) {
        cout << "bus topology";
    } else {
        cout << "unknown topology";
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}
