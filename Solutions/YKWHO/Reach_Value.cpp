#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) (a.begin(), a.end())
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int, int>

// multiply by 10 or 20 
// determine if can reach value N starting from N
// base case = when k == n or k >= n return
// otherwise open two branches, one w 10k and other w 20k

bool possible = false;
void solve(ll k, ll n) {
    if (possible || k > n) return;

    if (k == n) {
        possible = true;
        return;
    }

    solve(10 * k, n);
    solve(20 * k, n);
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        solve(1, n);
        cout << (possible ? "YES\n" : "NO\n"); 
        possible = false;
    }
}