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
#define MOD 1000000007
int dp[100006];

int count_paths(int src, int dest, vector<vi>& g) {
    if (src == dest) {
        return 1;
    }

    if (dp[src] != -1) {
        return dp[src];
    }

    int c = 0;
    for (auto neighbour : g[src]) {
        int x = count_paths(neighbour, dest, g);
        if (x != -1) {
            c = (c % MOD + x % MOD) % MOD;
        }
    }

    return (dp[src] = (c == 0 ? -1 : c));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[--a].push_back(--b);
    }

    memset(dp, -1, sizeof(dp));
    int c = count_paths(0, n - 1, g);
    cout << c;
    return 0;
}