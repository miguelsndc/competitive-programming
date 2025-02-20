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

void solve() {
    int n, undecided;
    cin >> n >> undecided;
    vi candidates(n);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    if (n == 1) {
        cout << "0\n";
        return;
    }

    int mx = *max_element(candidates.begin() + 1, candidates.end());
    int max_u = max(candidates[0] + undecided, mx);
    int winner = max_u == candidates[0] + undecided ? 0 : find(candidates.begin() + 1, candidates.end(), mx) - candidates.begin();
    ll sum = undecided;
    for (int i = 0; i < n; sum += candidates[i], ++i) {
        int ans;
        if (i == winner) {
            ans = 0;
        } else if (sum + candidates[i] >= max_u) {  // sum up to current i
            ans = i;
        } else {
            ans = i + 1;  // must remove max
        }

        cout << ans << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}