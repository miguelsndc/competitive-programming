#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> g[n];
    vector<ll> bikes(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[--u].push_back({--v, w});
        g[v].push_back({u, w});
    }
    for(int i = 0; i < n; i++) {
        cin >> bikes[i];
    }

    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> heap;
    vector<ll> dist(n, INT64_MAX);

    heap.push({0, 0});
    dist[0] = 0;

    while(!heap.empty()) {
        auto [d, from] = heap.top();
        heap.pop();
        if(d > dist[from]) continue;
        for (const auto &[to, weight]: g[from]) {
            ll cost = dist[from] + (weight * bikes[from]);
            if (cost < dist[to]) {
                dist[to] = cost;
                heap.push({dist[to], to});
                bikes[from] = min(bikes[from], bikes[to]);
            }
        }
    }

    cout << dist[n - 1] << '\n';
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