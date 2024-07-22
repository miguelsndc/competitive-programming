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

bool explore(int i, int j, int spikes, vector<vector<char>> &grid, vector<vb> &visited) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || spikes < 0 || grid[i][j] == '#') return false;
    if (grid[i][j] == 'x') return true;
    if (!visited[i][j]) {
        visited[i][j] = true;
        if (explore(i + 1, j, (grid[i][j] == 's') ? spikes - 1 : spikes, grid, visited)) return true;
        if (explore(i - 1, j, (grid[i][j] == 's') ? spikes - 1 : spikes, grid, visited)) return true;
        if (explore(i, j - 1, (grid[i][j] == 's') ? spikes - 1 : spikes, grid, visited)) return true;
        if (explore(i, j + 1, (grid[i][j] == 's') ? spikes - 1 : spikes, grid, visited)) return true;
        grid[i][j] = '#';
        visited[i][j] = false;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("m.in", "r", stdin);
    int n, m, j;
    cin >> n >> m >> j;
    vector<vector<char>> grid(n, vector<char>(m));
    int start_i, start_j;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> grid[i][k];
            if (grid[i][k] == '@') {
                start_i = i;
                start_j = k;
            }
        }
    }

    vector<vb> visited(n, vb(m));
    int possible = explore(start_i, start_j, j / 2, grid, visited);

    if (possible) {
        cout << "SUCCESS";
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}