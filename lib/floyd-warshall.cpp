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

// solution to all-pairs shortest path problem
// constructs a distance matrix containing the initial distance between the pairs of nodes
// loops are set to 0, nodes that aren't connected get a distance of infinity
// then, by rounds, a node is chosen to be intermediate between other two
// and the distances are recalculated
// once all nodes serve as intermediate, the algorithm is done and we have a matrix that contains
// the distance between any node in the graph
// Complexity is n^3, space is O(n), since the matrix comes from the graph

const int n = 5;
void fill_graph(vector<vi> &graph) {
    graph[0][2] = graph[2][0] = 1;
    graph[0][1] = graph[1][0] = 1;
    graph[1][3] = graph[3][1] = 2;
    graph[2][3] = graph[3][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[2][4] = graph[4][2] = 5;
}

#define INF 100  // declaring INT_MAX as infinity will result in overflow, use context based infinites,
// i.e, if all values are <= 1000, set INF as 1001 and so on.
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vi> graph(n, vi(n));
    fill_graph(graph);

    vector<vi> distance(n, vi(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                distance[i][j] = 0;
            } else if (graph[i][j]) {
                distance[i][j] = graph[i][j];
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << distance[i][j] spe;
        }
        cout << '\n';
    }

    return 0;
}