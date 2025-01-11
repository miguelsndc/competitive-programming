#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void traverse(int n, string type, vector<int> &entrances, vector<pair<int, int>> *g,set<int> &tb_exts,
    map<int, pair<ll, string>> & mp
) {
    priority_queue<pair<ll, int>, vector<pair<ll ,int>>, greater<pair<ll, int>>> pq; 
    vector<ll> dist(n, LONG_LONG_MAX);
    vector<bool> visited(n, false);
    for(int i: entrances) {
        pq.push({0LL, i});
        dist[i] = 0LL;
    }
    while(!pq.empty()) {
        auto [d, from] = pq.top(); pq.pop();
        if (visited[from]) continue;
        visited[from] = true;
        bool is_exit = false;
        if (tb_exts.find(from) != tb_exts.end()) {
            is_exit = true;
            // [node, (dist, type (c or e))]
            if (mp.find(from) == mp.end()) {
                mp[from] = {d, type};
            } else if (d < mp[from].first) {
                mp[from].first = d;
                mp[from].second = type;
            } else if (d == mp[from].first && mp[from].second != type) {
                mp[from].second = "tie";
            }

            tb_exts.erase(from);
        }
        if (is_exit) continue;
        for (const auto &[to, weight]: g[from]) {
            ll cost = dist[from] + weight;
            if (cost < dist[to]) {
                dist[to] = cost;
                pq.push({dist[to], to});
            }
        }
    }
}

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;

    vector<pair<int, int>> egg[n], chicken[n];
    vector<int> entrances(a);
    set<int> a_exts, b_exts; map<int, pair<ll, string>> result;

    for (int i = 0; i < m; i++) {
        int u, v, c, e; cin >> u >> v >> c >> e;
        --u, --v;
        chicken[u].push_back({v, c});
        egg[u].push_back({v, e});
    }

    for (int i = 0; i < a; i++) {
        cin >> entrances[i];
        --entrances[i];
    }

    for (int i = 0; i < b; i++) {
        int x; cin >> x;
        b_exts.insert(--x);
        a_exts.insert(x);
    }

    traverse(n, "chicken", entrances, chicken, a_exts, result);
    traverse(n, "egg", entrances, egg, b_exts, result);

    ll min_d = LONG_LONG_MAX;
    string ans = "tie";
    for (const auto &[node, p]: result) {
        auto [cost, type] = p;

        if (cost < min_d) {
            min_d = cost;
            ans = type;
       } else if (cost == min_d && (ans != type || type == "tie")) {
            ans = "tie";
       }
    }

    cout << ans;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
         solve();
    }
}