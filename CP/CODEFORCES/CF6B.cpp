#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
char p, c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    int grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            grid[i][j] = c;
        }
    }
    unordered_set<char> neighbours;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == p)
            {
                if (i > 0 && grid[i - 1][j] != '.' && grid[i - 1][j] != p)
                    neighbours.insert(grid[i - 1][j]);
                if (i < n - 1 && grid[i + 1][j] != '.' && grid[i + 1][j] != p)
                    neighbours.insert(grid[i + 1][j]);
                if (j > 0 && grid[i][j - 1] != '.' && grid[i][j - 1] != p)
                    neighbours.insert(grid[i][j - 1]);
                if (j < m - 1 && grid[i][j + 1] != '.' && grid[i][j + 1] != p)
                    neighbours.insert(grid[i][j + 1]);
            }
        }
    }

    cout << neighbours.size();
}