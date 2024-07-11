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

struct DisjointSet {
    vi parent;
    vi size;
    DisjointSet(int n) {
        parent.resize(n, -1);
        size.resize(n, 1);
    }

    int
    find(int curr) {
        if (parent[curr] == -1) {
            return curr;
        }
        return parent[curr] = find(parent[curr]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
    }
};

int dfs(pii u, vector<vector<pii>> &g, vb &visited, int max_e) {
    int node = u.f;
    int wt = u.s;
    if (visited[node]) return max_e;
    visited[node] = true;
    int new_max = max(max_e, wt);
    for (pii edge : g[node]) {
        int to = edge.f;
        if (!visited[to]) {
            new_max = max(new_max, dfs(edge, g, visited, new_max));
        }
    }
    return new_max;
}

void setIO(string name) {
    if (name.size() > 0) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    typedef tuple<int, int, int> triple;
    // setIO("d");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, x;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            return 0;
        }
        if (n == 0 || m == 0) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }

        vector<vector<pii>> g(n);
        vector<vector<pii>> mst(n);
        vector<triple> edges;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> x;
            g[a].push_back({b, x});
            g[b].push_back({a, x});
            edges.push_back({x, a, b});
        }

        make_heap(edges.begin(), edges.end(), std::greater<triple>{});
        int num_mst = n;
        DisjointSet dsu(n);
        int max_e = 0;
        vb visited(n);
        while (num_mst > 1) {
            int wt, u, v;
            pop_heap(edges.begin(), edges.end(), std::greater<triple>{});
            tie(wt, u, v) = edges.back();
            edges.pop_back();
            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                mst[u].push_back({v, wt});
                mst[v].push_back({u, wt});
                max_e = max(max_e, wt);
                visited[u] = visited[v] = true;
                num_mst--;
            }
        }

        auto it = find(visited.begin(), visited.end(), false);
        if (it != visited.end()) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            cout << max_e << '\n';
        }
    }

    return 0;
}