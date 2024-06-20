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

typedef tuple<int, int, int> edge;
void add_edge(int from, int to, int cost, vector<vector<edge>> &g) {
    g[from].push_back(make_tuple(from, to, cost));
}

vi bellman_ford(vector<vector<edge>> &g, int start) {
    int V = g.size();
    vi distance(V, INT_MAX);
    for (int u = 0; u < V - 1; u++) {
        for (vector<edge> &edge_list : g) {
            for (auto edge : edge_list) {
                int from, to, cost;
                tie(from, to, cost) = edge;
                if (distance[from] != INT_MAX && distance[from] + cost < distance[to]) {
                    distance[to] = distance[from] + cost;
                }
            }
        }
    }

    for (int u = 0; u < V - 1; u++) {
        for (vector<edge> &edge_list : g) {
            for (auto edge : edge_list) {
                int from, to, cost;
                tie(from, to, cost) = edge;
                if (distance[from] != INT_MAX && distance[from] + cost < distance[to]) {
                    distance[to] = INT_MIN;
                }
            }
        }
    }

    return distance;
}

const int N = 5;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<edge>> adj(N);
    add_edge(1, 2, 7, adj);
    add_edge(1, 3, 3, adj);
    add_edge(1, 4, 5, adj);
    add_edge(2, 3, 8, adj);
    add_edge(2, 5, 2, adj);
    add_edge(3, 5, 6, adj);
    return 0;
}