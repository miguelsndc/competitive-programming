#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

const int MAXN = 50001;
vector<int> g[MAXN];
int heavy[MAXN], cnt[100000], color[100000], subtree_size[MAXN], ans[MAXN], freq[MAXN];
set<int> colors;
int n, m; 

void find_subtree_sizes(int u, int parent = -1) {
    subtree_size[u] = 1;
    for (int child: g[u]) {
        if (child != parent) {
            find_subtree_sizes(child, u);
            subtree_size[u] += subtree_size[child];
        }
    }
}

// set colors per subtree then remove 
void add_colors(int u, int parent, int x) {
    cnt[color[u]] += x;
    for (int child: g[u]){
        if (child != parent && !heavy[child]) {
            add_colors(child, u, x);
        }
    }
}

void dfs(int u, int parent, int bigchild) {
    int max_size = -1, heavy_child = -1;
    for (int child: g[u]) {
        if (child != parent && subtree_size[child] > max_size) {
            heavy_child = child, max_size = subtree_size[child];
        } 
    }
    // process light child firts
    for (int child: g[u]) {
        if (child != parent && child != heavy_child) {
            dfs(child, u, 0);
        }
    }
    // then heavy
    if (heavy_child != -1) {
        dfs(heavy_child, u, 1), heavy[heavy_child] = 1;
    }
    add_colors(u, parent, 1);
    
    if (heavy[heavy_child] != -1) {
        heavy[heavy_child] = 0;
    }
    if (bigchild == 0) {
        add_colors(u, parent, -1);
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        heavy[i] = cnt[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= m; i++) {
        int u, c; cin >> u >> c;
        color[u] = c;
        colors.insert(c);
    }

    find_subtree_sizes(1);
    dfs(1, 0, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while((cin >> n >> m)) {
         solve();
    }
}