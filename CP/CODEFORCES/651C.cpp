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
    int n;
    cin >> n;
    vector<pii> p(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }

    unordered_map<int, ll> x_eq;
    unordered_map<int, ll> y_eq;
    map<pii, ll> rep;
    for (int i = 0; i < n; i++) {
        x_eq[p[i].f]++;
        y_eq[p[i].s]++;
        rep[p[i]]++;
    }

    ll count = 0;
    for (auto &[x, y] : x_eq) {
        count += y * (y - 1) / 2;
    }
    for (auto &[x, y] : y_eq) {
        count += y * (y - 1) / 2;
    }
    for (auto &[x, y] : rep) {
        count -= y * (y - 1) / 2;
    }

    cout << count;

    return 0;
}