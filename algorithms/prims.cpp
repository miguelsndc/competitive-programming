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

pair<vector<edge>, int> prim(int n, vector<vector<pii>> &g, int src = 0) {
    int m = n - 1;
    int edge_count, mst_cost = 0;
    vb visited(n);
    vector<edge> mst(m);

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

        mst[edge_count++] = e;
        mst_cost += get<0>(e);

        visited[to] = true;
        for (auto adj : g[to]) {
            if (!visited[adj.f]) {
                pq.push({adj.s, src, adj.f});
            }
        }
    }

    return {mst, mst_cost};
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, w;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    vector<edge> mst;
    int mst_cost;
    tie(mst, mst_cost) = prim(n, g, 0);

    cout << mst_cost;

    return 0;
}