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
    // 3 3 3 vol = 8
    // 2 * 2 * 2 = 8
    // loop through all possible values of a <= x b <= y and c <= z
    // we want a * b * c = k, so assume c = (k / ab)
    // then the solution is the amount of shifting spaces
    // (x - a + 1) (y - b+ 1) * (z - c + 1);
    int tc, x, y, z;
    ll k;
    cin >> tc;

    while (tc--) {
        ll ans = INT64_MIN;
        cin >> x >> y >> z >> k;
        for (int a = 1; a <= x; a++) {
            for (int b = 1; b <= y; b++) {
                ll c = k / (a * b);
                ll sol = (x - a + 1) * (y - b + 1) * (z - c + 1);  // shifting spaces
                // i can move x - a times to the x axis
                // +1 because if it's exactly equal to x we can't move, so the ans is 1
                // sounds about right
                if (a * b * c != k) {
                    sol = 0;
                }
                ans = max(ans, sol);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}