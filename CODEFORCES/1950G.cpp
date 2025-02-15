#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<ii>
#define vd vector<double>
#define si set<int>
#define mii map<int, int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define pb emplace_back
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

const int maxn = 16;
string g[maxn], w[maxn]; int mat[maxn][maxn], dp[(1 << maxn)][maxn];
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> g[i] >> w[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = (g[i] == g[j] || w[i] == w[j]);
        }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) dp[mask][i] = 0; 
    }
    for (int i = 0; i < n; i++) {
        dp[(1 << i)][i] = 1;
    }
    int ans = -1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            // doesnt have song i
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                // adding j
                int nmask = (mask | (1 << j));
                if (mat[i][j]) {
                    dp[nmask][j] = max(dp[nmask][j], dp[mask][i] + 1);
                }
                dp[nmask][i] = max(dp[nmask][i], dp[mask][i]);
            }
            ans = max(ans, dp[mask][i]);
        }
    }
    cout << n - ans << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}