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
#define MOD 1000000007

ll gcd(ll a, ll b) {
    if (a && b) {
        while ((a %= b) && (b %= a));
    }
    return a ^ b;
}

ll exp(ll b, ll p, ll m) {
    ll r = 1;
    while (p) {
        if (p & 1)
            r = (__int128)r * b % m;
        b = (__int128)b * b % m;
        p >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    ll a, b, n;
    cin >> t;
    while (t--) {
        cin >> a >> b >> n;
        ll m = a == b ? MOD : a - b;
        ll s = (exp(a, n, m) + exp(b, n, m)) % m;
        cout << gcd(a - b, s) % MOD << '\n';
    }

    return 0;
}