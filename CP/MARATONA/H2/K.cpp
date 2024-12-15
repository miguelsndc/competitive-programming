#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)


void solve(int r, int c, ll *cnt, int depth, int k, vi&rdiag,vi&ldiag,vector<vi>&vis, int n) {

    if (depth == k) {
        cnt[0]++; return;
    }

    if (r == n) return;

    for (int j = 0; j < n; j++) {
        if (!vis[r][j] && rdiag[r - j + n] == 0 && ldiag[r + j] == 0) {
            vis[r][j] = 1;
            rdiag[r - j + n] = 1;
            ldiag[r + j] = 1; 

            solve(r + 1, j, cnt, depth + 1, k, rdiag, ldiag, vis, n);

            vis[r][j] = 0;
            rdiag[r - j + n] = 0;
            ldiag[r + j] = 0; 
        }
    }
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll c = 0;
    int n, k;
    vi rdiag(2 * 8 - 1);
    vi ldiag(2 * 8 - 1);
    vector<vi> vis(8, vi(8));
    while((cin >> n >> k) && n && k) {
        if (k > 2 * n) {
            cout << 0 << '\n';
            continue;
        }

        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                solve(0, 0, &cnt, 0, k, rdiag, ldiag, vis, n);
            }
        }
        cout << cnt << '\n';
    }
}