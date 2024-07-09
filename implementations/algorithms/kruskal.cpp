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

void add_edge(vector<vector<pii>> &g, int from, int to, int weight) {
    g[from].push_back({to, weight});
    g[to].push_back({from, weight});
}

struct DisjointSet {
    vi parent;
    vi size;
    DisjointSet(int n) {
        parent.resize(n, -1);
        size.resize(n, 1);
    }

    int
    find(int curr) {
        if (parent[curr] == -1) {
            return curr;
        }
        return parent[curr] = find(parent[curr]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

const int n = 5;
const int m = 7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<pii>> g(n);
    add_edge(g, 0, 1, 10);
    add_edge(g, 1, 2, 2);
    add_edge(g, 0, 2, 3);
    add_edge(g, 1, 3, 5);
    add_edge(g, 0, 3, 20);
    add_edge(g, 2, 4, 15);
    add_edge(g, 3, 4, 11);

    int edge_count = 0;
    vector<tuple<int, int, int>> heap(m);
    vector<vb> visited(m, vb(m));

    for (int i = 0; i < n; i++) {
        for (auto edge : g[i]) {
            if (!visited[i][edge.f]) {
                heap[edge_count++] = {edge.s, i, edge.f};  // (weight, from, to);
                visited[i][edge.f] = visited[edge.f][i] = true;
            }
        }
    }

    make_heap(heap.begin(), heap.end(), greater<tuple<int, int, int>>{});
    vector<vector<pii>> mst(n);
    DisjointSet dsu(n);
    int num_mst = n;
    while (num_mst > 1) {
        int wt, from, to;
        pop_heap(heap.begin(), heap.end(), std::greater<tuple<int, int, int>>{});
        tie(wt, from, to) = heap.back();
        heap.pop_back();
        if (dsu.find(from) != dsu.find(to)) {
            dsu.unite(from, to);
            mst[from].push_back({to, wt});
            num_mst--;
        }
    }

    return 0;
}