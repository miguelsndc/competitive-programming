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

int solve(int n) {
    vi dp(n + 1, 1e9 + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k > 0) {
            int d = k % 10;
            dp[i] = min(dp[i], dp[i - d] + 1);
            k /= 10;
        }
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}