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
    int tc = 1;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;
        ll l = max(0LL, n - m), r = n + m, ans = 0;
        for (int i = 31; ~i; i--) {
            if ((l & (1LL << i)) || (r & (1LL << i)) || (l >> (i + 1)) != (r >> (i + 1))) {
                ans |= (1LL << i);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}