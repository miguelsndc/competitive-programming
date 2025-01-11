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

// bellman ford algorithm
// - works with negative weighted graphs
// - can detect negative cycles
// - decent average case
// we pick a start node, set the distance to 0 then set all the other distances to infinity.
// then we loop n - 1 times through all the edges, updating the distances as follows
// current_distance = min(current distance, next vertex distance + weight)
// do that for n -1 times because the largest possible path from two nodes has n - 1 edges.
// then run again to check if any distance changed, if yes, then we have a negative cycle
// it changes because negative cycles makes the shortest path arbitrarily small, because each iteration
// we reduce the distance

const int n = 5;
#define INF INT_MAX
typedef tuple<int, int, int> edge;
void add_edge(int from, int to, int cost, vector<edge> &graph) {
    graph.push_back(make_tuple(from, to, cost));
}

vi bellman_ford(vector<edge> &edges, int V, int start) {
    vi distance(V + 1, INT_MAX);
    distance[start] = 0;

    int relaxed = true;
    for (int v = 0; v < V - 1 && relaxed; v++) {
        relaxed = false;
        for (auto edge : edges) {
            int from, to, cost;
            tie(from, to, cost) = edge;
            if (distance[from] != INT_MAX && distance[from] + cost < distance[to]) {
                distance[to] = distance[from] + cost;
                relaxed = true;
            }
        }
    }

    relaxed = true;
    for (int v = 0; v < V - 1 && relaxed; v++) {
        relaxed = false;
        for (auto edge : edges) {
            int from, to, cost;
            tie(from, to, cost) = edge;
            if (distance[from] != INT_MAX && distance[from] + cost < distance[to]) {
                relaxed = true;
                distance[to] = INT_MIN;
            }
        }
    }

    return distance;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<edge> graph;  // adjacency list (index, weight)
    add_edge(1, 2, 7, graph);
    add_edge(1, 3, 3, graph);
    add_edge(1, 4, 5, graph);
    add_edge(2, 3, 8, graph);
    add_edge(2, 5, 2, graph);
    add_edge(3, 5, 6, graph);

    vi distance = bellman_ford(graph, 5, 1);

    return 0;
}