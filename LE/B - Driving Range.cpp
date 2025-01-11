#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "
#define edge tuple<int, int, int>

int mst_max_edge(int n, vector<vector<pii>> &g, int src = 0) {
    int m = n - 1;
    int edge_count = 0;
    vb visited(n);
    int max_e = 0;

    priority_queue<edge, vector<edge>, greater<edge>> pq;

    visited[src] = true;
    for (auto adj : g[src]) {
        if (!visited[adj.f]) {
            pq.push({adj.s, src, adj.f});  // (weight, from, to)
        }
    }

    while (!pq.empty() && edge_count < m) {
        edge e = pq.top();
        pq.pop();
        int to = get<2>(e);

        if (visited[to]) {
            continue;
        }

        int wt = get<0>(e);
        max_e = max(max_e, wt);
        edge_count++;

        visited[to] = true;
        for (auto adj : g[to]) {
            if (!visited[adj.f]) {
                pq.push({adj.s, src, adj.f});
            }
        }
    }

    if (edge_count != m) {
        return INT32_MAX;
    }
    return max_e;
}

int main() {
    typedef tuple<int, int, int> triple;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, x;
    while (cin >> n >> m, n) {
        if (m == 0) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<vector<pii>> g(n);
        vector<vector<pii>> mst(n);

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> x;
            g[a].push_back({b, x});
            g[b].push_back({a, x});
        }

        int max_e = mst_max_edge(n, g, 0);

        if (max_e == INT32_MAX) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << max_e << '\n';
        }
    }
    return 0;
}