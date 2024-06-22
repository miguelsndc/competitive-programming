#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

// perform depth-first-search
// pass the parent as a parameter as well
// if between the adjacent nodes there are visited ones that are not the parent, there's a cycle
// use the previous[] technique to record the path
// make sure to pushback the starting node to the end
// if there's no cycle then print IMPOSSIBLE

int cycle = false;

void answer(int node, vi &path) {
    cycle = true;
    vi actual_cycle = {node};
    for (int i = path.size() - 1; i >= 0; i--) {
        actual_cycle.push_back(path[i]);
        if (path[i] == node) {  // avoid subsequent edges that aren't in the cycle but are part of dfs
            break;
        }
    }
    cout << actual_cycle.size() << '\n';
    for (int node : actual_cycle) {
        cout << node spe;
    }
}

void dfs(int node, int parent, vector<vi> &graph, vi &visited, vi &path) {
    if (cycle) return;
    if (visited[node]) {        // if node and parent are different (check like 47)
        if (path.size() > 2) {  // there's a back edge, cycle detected and we're done
            answer(node, path);
        }
        return;
    }
    visited[node] = true;
    path.push_back(node);
    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node, graph, visited, path);
        }
    }
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> graph(n + 1);
    vi visited(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vi path;
            dfs(i, -1, graph, visited, path);
        }
    }
    if (!cycle) {
        cout << "IMPOSSIBLE" << '\n';
    }
}