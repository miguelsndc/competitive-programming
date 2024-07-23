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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> bitmap(n, vector<char>(m, 0));
    queue<pii> q;
    vector<vi> dist(n, vi(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> bitmap[i][j];
            if (bitmap[i][j] == '1') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int i = q.front().f, j = q.front().s;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int r = i + dx[k];
            int c = j + dy[k];
            if (r < 0 || c < 0 || r >= n || c >= m || dist[r][c] != -1) continue;
            dist[r][c] = dist[i][j] + 1;
            q.push({r, c});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] spe;
        }
        cout << '\n';
    }
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