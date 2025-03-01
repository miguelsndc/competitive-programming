#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

const int MAXN = 2e5 + 5;

struct DisjointSet {
    int parents[MAXN];
    int sizes[MAXN];

    void init(int n) {
        for (int i = 1; i <= n; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }
    
    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }
    
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true; // (some condition met for component);
    }
};