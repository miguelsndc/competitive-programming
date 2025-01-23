#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

const int MAXN = 5e4 + 1;
vector<int> g[MAXN];
int ans[MAXN];
vector<int> sizes(MAXN), parents(MAXN);

void dfs(int u, int parent) {
    for (int v: g[u]) {
        if (v != parent) {
            dfs(v, u);

            if (colors[u].size() < colors[v].size()) {
                swap(colors[u], colors[v]);
            }

            for (int x: colors[v]) colors[u].insert(x);
        }
    }

    ans[u] = colors[u].size();
}

void solve(int n, int m) {
    for (int i = 1; i <= n; i++) {
        colors[i].clear(); g[i].clear();
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= m; i++) {
        int u, c; cin >> u >> c;
        colors[u].insert(c);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
         solve(n, m);
    }
}