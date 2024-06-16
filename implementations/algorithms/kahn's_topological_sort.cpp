#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " "

int *kahn_topsort(vector<vi> &graph) {
    int n = graph.size();
    vi in_degree(n);
    for (int i = 0; i < n; i++) {
        for (int to : graph[i]) {
            in_degree[to]++;
        }
    }
    // queue is the set of nodes with no incoming edges;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    int index = 0;
    int *order = new int[n];
    while (!q.empty()) {
        int at = q.front();
        q.pop();

        order[index++] = at;
        for (int to : graph[at]) {
            // simulate removal of at node, decrease in degree of adjacent nodes
            in_degree[to]--;
            if (in_degree[to] == 0) {
                q.push(to);
            }
        }
    }

    if (index != n) {
        return nullptr;  // cycle detected
    }

    return order;
}

void add_edge(int from, int to, vector<vi> &graph) {
    graph[from].push_back(to);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int n = 7;
    vector<vi> graph(n);

    add_edge(0, 3, graph);
    add_edge(3, 6, graph);
    add_edge(1, 4, graph);
    add_edge(4, 5, graph);
    add_edge(5, 6, graph);
    add_edge(2, 5, graph);

    int *order = kahn_topsort(graph);
    for (int i = 0; i < n; i++) {
        cout << order[i] sp;
    }

    return 0;
}