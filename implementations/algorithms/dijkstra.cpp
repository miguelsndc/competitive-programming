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

// dist/prev
tuple<vi, vi>
dijkstra(vector<vector<pii>> &g, int start) {
    vb visited(g.size(), false);  // marks the visited ones
    vi dist(g.size(), INT_MAX);   // dist[i] would return the distance from start to i
    vi prev(g.size(), -1);        // the path tracker
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // weight / index pair because pq sorts by first element
    prev[start] = -2;
    pq.push(make_pair(0, start));  // weight/index
    while (!pq.empty()) {
        pii p = pq.top();
        int min_val = p.first, index = p.second;
        pq.pop();
        visited[index] = true;
        if (dist[index] < min_val) {
            continue;
        }
        for (auto edge : g[index]) {
            if (visited[edge.f]) continue;
            int new_dist = dist[index] + edge.s;
            if (new_dist < dist[edge.f]) {
                prev[edge.f] = index;
                dist[edge.f] = new_dist;
                pq.push({dist[edge.f], edge.f});
            }
        }
    }
    return make_tuple(dist, prev);
};

void add_edge(int from, int to, int weight, vector<vector<pii>> &g) {
    g[from].push_back(make_pair(to, weight));
    g[to].push_back(make_pair(from, weight));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<pii>> graph(5);

    add_edge(0, 1, 1, graph);
    add_edge(0, 2, 1, graph);
    add_edge(1, 3, 2, graph);
    add_edge(2, 3, 1, graph);
    add_edge(2, 4, 5, graph);
    add_edge(3, 4, 1, graph);

    vi dist, prev;
    tie(dist, prev) = dijkstra(graph, 0);
    vi path;
    int e = 4;

    if (dist[e] == INT_MAX) {
        cout << "unreachable";
        return 0;
    }

    for (int at = e; at != -2; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    for (int n : path) {
        cout << n spe;
    }

    return 0;
}