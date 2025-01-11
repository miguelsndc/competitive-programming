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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;

    ll dp[n + m + 1][n + m + 1];

    for (int line = 0; line <= n + m; line++) {
        for (int i = 0; i <= line; i++) {
            if (i == 0 || line == i)
                dp[line][i] = 1;
            else
                dp[line][i] = dp[line - 1][i - 1] + dp[line - 1][i];
        }
    }

    ll sol = 0;
    for (int b = 4; b <= n; b++) {
        for (int c = 1; c <= m; c++) {
            if (b + c == t) {
                sol += dp[n][b] * dp[m][t - b];
            }
        }
    }

    std::cout << sol;

    return 0;
}