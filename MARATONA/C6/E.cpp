#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

void solve() {
    int n, m; cin >> n >> m;
    int d; cin >> d;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    ii start, end;

    enum pos {
        up,
        down,
        left,
        right
    };

    vector<array<int, 3>> cops;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char v = grid[i][j];

            if (v == 'F') {
                start = {i, j};
            } else if (v == 'H') {
                end = {i, j};
            }
            if(v == '>') {
                cops.push_back({i, j, pos::right});
            }
            if(v == '<') {
                cops.push_back({i, j, pos::left});
            }
            if(v == 'v') {
                cops.push_back({i, j, pos::down});
            }
            if(v == '^') {
                cops.push_back({i, j, pos::up});
            }
        }
    }


    for (auto c: cops) {
        auto [i, j, p] = c; 

        if (p == pos::up) {
            int cnt = 0;
            while(i - cnt >= 0 && cnt <= d) {
                if ((grid[i - cnt][j] == '.' || grid[i - cnt][j] == 'F' || grid[i - cnt][j] == 'H' || i - cnt == i || grid[i - cnt][j] == '$')) {
                    grid[i - cnt][j] = '$';
                    cnt++;
                } else {
                    break;  
                }
            }
        }
        if (p == pos::left) {
            int cnt = 0;
            while(j - cnt >= 0 && cnt <= d) {
                if ((grid[i][j - cnt] == '.' || grid[i][j - cnt] == 'F' || grid[i][j - cnt] == 'H' || j - cnt == j || grid[i][j - cnt] == '$')) {
                    grid[i][j - cnt] = '$';
                    cnt++;
                } else {break;}
            }
        }
        if (p == pos::right) {
            int cnt = 0;
            while(j + cnt < m && cnt <= d) {
                if ((grid[i][j + cnt] == '.' || grid[i][j + cnt] == 'F' || grid[i][j + cnt] == 'H' || j + cnt == j || grid[i][j + cnt] == '$')) {
                    grid[i][j + cnt] = '$';
                    cnt++;
                } else {break;}
            }
        }
        if (p == pos::down) {
            int cnt = 0;
            while(i + cnt < n && cnt <= d) {
                if ((grid[i + cnt][j] == '.' || grid[i + cnt][j] == 'F' || grid[i + cnt][j] == 'H' || i  + cnt == i || grid[i + cnt][j] == '$')) {
                    grid[i + cnt][j] = '$';
                    cnt++;
                } else {break;}
            }
        }
    }

    queue<ii> q;
    q.push(start);
    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    grid[start.first][start.second] = '$';

    bool can = false;
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = row + dy[i];
            int nc = col + dx[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '$' && grid[nr][nc] != '#') {
                if (grid[nr][nc] == 'H') {
                    can = true;
                }
                q.push({nr, nc});
                grid[nr][nc] = '$';
            }
        }
    }

    cout << (can ? "YES" : "NO");
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}