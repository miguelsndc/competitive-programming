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

void dfs(int u, vector<vi> &graph, vb &visited) {
    if (visited[u]) return;
    visited[u] = true;
    for (int v = 0; v < graph.size(); v++) {
        if (!visited[v])
            dfs(v, graph, visited);
    }
    // backtrack here if needed
}

const int N = 10;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vi> graph(N, vi(N));
    vb visited(N);

    dfs(0, graph, visited);

    return 0;
}