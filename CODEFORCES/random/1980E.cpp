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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    vector<vi> b(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    int nm = n * m;
    vi pos1i(nm), pos2i(nm), pos1j(nm), pos2j(nm);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = a[i][j] - 1;
            int y = b[i][j] - 1;
            pos1i[x] = pos2i[y] = i;
            pos1j[x] = pos2j[y] = j;
        }
    }

    vector<set<int>> pi(nm), pj(nm);
    for (int i = 0; i < nm; i++) {
        int i1 = pos1i[i], i2 = pos2i[i];
        int j1 = pos1j[i], j2 = pos2j[i];
        pi[i1].insert(i2);
        pj[j1].insert(j2);  // row and column position of a and b
    }

    for (int u = 0; u < nm; u++) {
        if (pi[u].size() > 1 || pj[u].size() > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
