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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}