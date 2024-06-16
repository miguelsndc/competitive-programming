#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// Graph is required to be a DAG (Directed Acyclic Graph);

int dfs(int i, int at, vector<vi> &adj, vector<bool> &V, int *ordering) {
    V[at] = true;
    for (auto u : adj[at]) {
        if (!V[u])
            i = dfs(i, u, adj, V, ordering);
    }
    ordering[i] = at;
    return i - 1;
}

void add_edge(int u, int v, vector<vi> &adj) {
    adj[u].push_back(v);
}

int *topological_sort(vector<vi> &graph) {
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

int n = 7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vi> adj(n);

    add_edge(0, 3, adj);
    add_edge(3, 6, adj);
    add_edge(1, 4, adj);
    add_edge(4, 5, adj);
    add_edge(5, 6, adj);
    add_edge(2, 5, adj);

    int *ordering = topological_sort(adj);

    for (int i = 0; i < n; i++) {
        cout << ordering[i] << ' ';
    }

    return 0;
}