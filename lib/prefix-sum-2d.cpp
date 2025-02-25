#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

int n, m;
vector<vector<ll>> pref(n, vector<ll>(m, 0));
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

int maxn = 1005, maxm = 1005;
vector<vector<ll>> pref(maxn, vector<ll>(maxm, 0));

void solve() {
    vector<vector<ll>> grid(n + 1, vector<ll>(n + 1));
    // build code
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = grid[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    // previous row, previous col, to row, to col
    int pr, pc, tr, tc;
    int ans = pref[tr][tc] - pref[tr][pc - 1] - pref[pr - 1][tc] + pref[pr - 1][pc - 1];
}

