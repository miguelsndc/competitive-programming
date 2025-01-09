#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int table_entrance[200005], table_exit[200005];

void solve() {
    int n, m, a, b; cin >>n>>m>>a>>b;
    vector<pair<int,int>> egg[n], chicken[n];
    for (int i = 0; i < m; i++) {
        int u, v, c, e; cin >> u >> v >> c >> e;
        egg[u].push_back({v, e});
        chicken[u].push_back({v, c});
    }
    
    vector<int> entrances(a), exits(b);
    for (int i = 0; i < a; i++) {
        cin >> entrances[i];
        table_entrance[entrances[i]] = 1;
    }
    for (int i = 0; i < b; i++) {
        cin >> exits[i];
        table_exit[exits[i]] = 1;
    }

    vector<int> dist(n, INT32_MAX);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (int i = 0; i < a; i++) {
        pq.push({0, entrances[i]});
        dist[entrances[i]] = 0;
    }

    while(!pq.empty()) {
        auto[d, from, type] = pq.top();
        pq.pop();

        if (type != 2) {
            for (const auto&[neighbour, weight]: chicken[from]) {
                if (dist[from] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[from] + weight;
                    pq.push({dist[neighbour], neighbour, 1});
                }
            }
        }
        if (type != 1) {
            for (const auto&[neighbour, weight]: egg[from]) {
                if (dist[from] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[from] + weight;
                    pq.push({dist[neighbour], neighbour, 1});
                }
            }
        }
    }
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