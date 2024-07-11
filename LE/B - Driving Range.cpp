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

void setIO(string name) {
    if (name.size() > 0) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    typedef tuple<int, int, int> triple;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, x;
    while (cin >> n >> m, n) {
        vector<vector<pii>> g(n);
        vector<vector<pii>> mst(n);

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> x;
            g[a].push_back({b, x});
            g[b].push_back({a, x});
        }

        vb visited(n);
        vi cost(n, INT32_MAX);

        priority_queue<triple, vector<triple>, greater<triple>> pq;
        int src = -1;
        for (int i = 0; i < n; i++) {
            if (g[i].size() > 0) {
                src = i;
                break;
            }
        }

        if (src == -1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        pii fe = g[src][0];
        pq.push({fe.s, src, fe.f});
        cost[src] = 0;

        int edge_cnt = 0;
        int max_e = 0;
        while (!pq.empty() && edge_cnt != (n - 1)) {
            int wt, from, to;
            tie(wt, from, to) = pq.top();
            pq.pop();
            edge_cnt++;
            visited[to] = true;
            for (auto adj : g[to]) {
                if (visited[adj.f]) continue;
                if (cost[adj.f] > adj.s) {
                    cost[adj.f] = adj.s;
                    max_e = max(max_e, adj.s);
                    pq.push({adj.s, from, adj.f});
                }
            }
        }

        if (find(visited.begin(), visited.end(), false) == visited.end()) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }

        cout << max_e << '\n';
    }

    return 0;
}