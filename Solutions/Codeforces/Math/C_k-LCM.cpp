#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define FOR(var, k, n) for (int var = k; var < n; var++)
#define FORI(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n,k;cin>>n>>k;
        if (n % 2) {
            cout << n/2 << ' ' << n/2 << ' ' << 1 << '\n';
        } else {
            int t = n / 2;
            if (t % 2 == 0) {
                cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
            } else {
                cout << n/2 - 1<< ' ' << n/2 - 1 << ' ' << 2 << '\n';
            }
        }
    }
}