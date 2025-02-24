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
