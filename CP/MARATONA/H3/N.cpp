#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

bool isvalid(int row, int col, vector<string> &grid) {
    return (
        row >= 0 && row < grid.size() &&
        col >= 0 && col < grid[0].size() 
    );
}

vector<int> dirs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, d; cin >> n >> m >> d;
    vector<string> grid(n, string(m, '.'));
    array<int, 2> start;
    array<int, 2> finish;
    queue<array<int, 3>> monsters;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') start = {i, j};
            else if (grid[i][j] == 'F') finish = {i, j};
            else if (grid[i][j] == 'M') {monsters.push({i, j, 0}); grid[i][j] = '#';};
        }
    }

    while(!monsters.empty()) {
        auto [row, col, accdist] = monsters.front();
        monsters.pop();
        if(dist[row][col] == -1) {
            dist[row][col] = accdist;
            if (dist[row][col] <= d) {
                grid[row][col] = '#';
            }
        }
        for (int i = 0; i < 4; i++) {
            int dy = row + dirs[i][0];
            int dx = col + dirs[i][1];
            if (isvalid(dy, dx, grid) && dist[dy][dx] == -1) {
                monsters.push({dy, dx, accdist + 1});
            }
        }
    }

    if (dist[start[0]][start[1]] <= d) {
        cout << -1;
        return 0;
    }

    if (dist[finish[0]][finish[1]] <= d) {
        cout << -1;
        return 0;
    }

    queue<array<int, 2>> player;
    player.push(start);
    grid[start[0]][start[1]] = '#';
    auto [finish_y, finish_x] = finish;

    int can = false;
    vector<vector<int>> player_dist(n, vector<int>(m, -1));
    player_dist[start[0]][start[1]] = 0;
    while(!player.empty()) {
        auto [row, col] = player.front();
        player.pop();
        if (row == finish_y && col == finish_x) {
            can = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int dy = row + dirs[i][0];
            int dx = col + dirs[i][1];
            if (isvalid(dy, dx, grid) && grid[dy][dx] != '#' && player_dist[dy][dx] == -1 && dist[dy][dx] > d) {
                player_dist[dy][dx] = player_dist[row][col] + 1;
                grid[dy][dx] = '#';
                player.push({dy,dx});
            }
        }
    }
    cout << player_dist[finish_y][finish_x];
}