#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009
#define all(a) begin(a), end(a)

void solve() {
    int n, m; cin >> n >> m;
    int start_y, start_x; cin >> start_y >> start_x;
    int end_y, end_x; cin >> end_y >> end_x;
    
    int grid[105][105];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    deque<pair<array<int, 2>, set<int>>> dq;
    dq.push_back({{start_y, start_x}, set<int>{grid[start_y][start_x]}});

    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};

    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    vis[start_y][start_x] = true;

    int k = INT32_MAX;

    while(!dq.empty()) {
        int y = dq.front().first[0];
        int x = dq.front().first[1];
        set<int> v = set<int> {all(dq.front().second)}; // no maximo umas 34 operaçoes

        dq.pop_front();

        if(y == end_y && x == end_x) {
            k = v.size();
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || ny > n || nx < 1 || nx > n || vis[ny][nx]) continue;

            vis[ny][nx] = true;
            pair<array<int, 2>, set<int>> p = {{ny, nx}, set<int>{all(v)}};
            p.second.insert(grid[ny][nx]);

            if (p.second.size() == v.size()) {
                dq.push_front(p);
            } else {
                dq.push_back(p);
            }
        }
    }

    cout << k;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
         solve();
    }
}