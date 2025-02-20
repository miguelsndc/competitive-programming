
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

bool f(ll n) {
    ll i = 2;
    while (i * i <= n) {
        if (n % (i * i) == 0) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a;
    cin >> a;
    ll ans = 1;
    ll x = a;
    for (ll i = 2; i * i <= a; i++) {
        if (x % i == 0) {
            ans *= i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1)
        ans *= x;
    cout << ans;

    return 0;
}