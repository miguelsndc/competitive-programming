#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) {
        from = f;
        to = t;
        weight = w;
    }
};

int dfs(int i, int at, vector<vector<Edge>> &adj, vector<bool> &V, int *ordering) {
    V[at] = true;
    for (auto u : adj[at]) {
        if (!V[u.to])
            i = dfs(i, u.to, adj, V, ordering);
    }
    ordering[i] = at;
    return i - 1;
}

void add_edge(int u, int v, int w, vector<vector<Edge>> &adj) {
    Edge e = Edge(u, v, w);
    adj[u].push_back(e);
}

int *topological_sort(vector<vector<Edge>> &graph) {
    int no_nodes = graph.size();
    int i = no_nodes - 1;
    int *ordering = new int[no_nodes];
    vector<bool> visited(no_nodes);

    for (int at = 0; at < no_nodes; at++) {
        if (!visited[at]) {
            i = dfs(i, at, graph, visited, ordering);
        }
    }

    return ordering;
}

int *dag_shortest_path(vector<vector<Edge>> &graph, int start) {
    int no_nodes = graph.size();
    int *topsort = topological_sort(graph);
    int *dist = new int[no_nodes];
    memset(dist, -1, no_nodes * sizeof(int));
    dist[start] = 0;
    for (int i = 0; i < no_nodes; i++) {
        int node_i = topsort[i];
        if (dist[node_i] != -1) {
            vector<Edge> &adjacent = graph[node_i];
            for (Edge adj : adjacent) {
                int new_dist = dist[node_i] + adj.weight;
                if (dist[adj.to] == -1)
                    dist[adj.to] = new_dist;
                else
                    dist[adj.to] = min(dist[adj.to], new_dist);
            }
        }
    }
    delete topsort;
    return dist;
}

int n = 7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<Edge>> adj(n);

    add_edge(0, 3, 1, adj);
    add_edge(3, 6, 2, adj);
    add_edge(1, 4, 2, adj);
    add_edge(4, 5, 2, adj);
    add_edge(4, 6, 4, adj);
    add_edge(5, 6, 1, adj);
    add_edge(2, 5, 2, adj);

    int *ordering = topological_sort(adj);
    int *dist = dag_shortest_path(adj, 0);
    cout << dist[6];

    return 0;
}