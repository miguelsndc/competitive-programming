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

#define Edge tuple<int, int, int>  // (wt, from, to)

int prims(vector<vector<pii>> &g, int n, int src) {
    int min_cost = 0, m = n - 1, edge_count = 0;
    vb visited(n);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    visited[src] = true;
    for (auto adj : g[src]) {
        pq.push({adj.s, src, adj.f});
    }

    while (!pq.empty() && edge_count < m) {
        int from, to, wt;
        tie(wt, from, to) = pq.top();
        pq.pop();

        if (visited[to])
            continue;

        visited[to] = true;
        min_cost += wt;

        for (auto adj : g[to]) {
            if (!visited[adj.f])
                pq.push({adj.s, to, adj.f});
        }
    }

    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, o, i = 1;
    while (cin >> c >> o) {
        if (c == 0 && o == 0) {
            return 0;
        }

        int a, b, x;
        vector<vector<pii>> g(c);
        for (int i = 0; i < o; i++) {
            cin >> a >> b >> x;
            g[a].push_back({b, x});
            g[b].push_back({a, x});
        }
        int min_cost = prims(g, c, 0);
        cout << "Caso " << i << ": " << min_cost << '\n';
        i++;
    }

    return 0;
}