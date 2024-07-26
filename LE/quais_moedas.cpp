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
    int tc, n, j = 1;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vi dp(n + 1, 0);
        vi coins(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> coins[i];
        dp[0] = 0;
        dp[1] = coins[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(coins[i] + dp[i - 2], dp[i - 1]);
        }
        vi path;
        for (int i = n; i > 0;) {
            if (dp[i] == dp[i - 1]) {
                i -= 1;
            } else {
                path.push_back(coins[i]);
                i -= 2;
            }
        }

        if (n == 0) {
            cout << "Caso " << j << ": 0=0\n";
            j++;
            continue;
        }

        reverse(path.begin(), path.end());
        cout
            << "Caso " << j << ": ";
        for (int i = 0; i < path.size() - 1; i++) {
            cout << path[i] << '+';
        }
        if (path.size() > 0) {
        }
        cout << path[path.size() - 1];
        cout << "=" << dp[n] << "\n";
        j++;
    }
    return 0;
}