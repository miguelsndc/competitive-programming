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

void solve(int i) {
    int n, m, src, dest, a, b, x;
    cin >> n >> m >> src >> dest;
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        g[a].push_back({b, x});  // (weight, to)
        g[b].push_back({a, x});
    }

    vb visited(n);
    vi distance(n, INT32_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    distance[src] = 0;
    while (!pq.empty() && (pq.top()).s != INT32_MAX) {
        int cost = pq.top().f, to = pq.top().s;
        pq.pop();
        visited[to] = true;
        if (to == dest) {
            break;
        }
        if (distance[to] < cost) {
            continue;
        }
        for (auto edge : g[to]) {
            int u = edge.f, wt = edge.s;
            if (visited[u]) continue;
            int new_dist = distance[to] + wt;
            if (new_dist < distance[u]) {
                distance[u] = new_dist;
                pq.push({new_dist, u});
            }
        }
    }
    cout << "Case #" << i << ": ";
    if (distance[dest] == INT32_MAX) {
        cout << "unreachable" << '\n';
    } else {
        cout << distance[dest] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    int i = 1;
    while (tc--) {
        solve(i);
        i++;
    }
    return 0;
}