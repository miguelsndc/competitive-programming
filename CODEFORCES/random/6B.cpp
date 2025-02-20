#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    char p;
    cin >> n >> m >> p;
    char table[n][m];
    vii ppos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char t;
            cin >> t;
            table[i][j] = t;
            if (t == p) {
                ppos.push_back(make_pair(i, j));
            }
        }
    }

    int c = 0;
    bitset<257> seen;
    for (ii pos : ppos) {
        int i = pos.first;
        int j = pos.second;

        if (i > 0 && table[i - 1][j] != '.' && table[i - 1][j] != p && !seen[table[i - 1][j]]) {
            c++;
            seen[table[i - 1][j]] = 1;
        }
        if (i < n - 1 && table[i + 1][j] != '.' && table[i + 1][j] != p && !seen[table[i + 1][j]]) {
            c++;
            seen[table[i + 1][j]] = 1;
        }
        if (j > 0 && table[i][j - 1] != '.' && table[i][j - 1] != p && !seen[table[i][j - 1]]) {
            c++;
            seen[table[i][j - 1]] = 1;
        }
        if (j < m - 1 && table[i][j + 1] != '.' && table[i][j + 1] != p && !seen[table[i][j + 1]]) {
            c++;
            seen[table[i][j + 1]] = 1;
        }
    }

    cout << c;

    return 0;
}