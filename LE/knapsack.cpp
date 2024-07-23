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

    int cap, n;
    cin >> cap >> n;
    vi w(n + 1);
    vi v(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    vector<vi> dp(n + 1, vi(cap + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][cap];

    return 0;
}