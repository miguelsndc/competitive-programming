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

// given a number of hamburgers, find the maximum amount of money he'll need to spend;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int cb = 0, cs = 0, cc = 0;
    for (char c : s) {
        if (c == 'B') cb++;
        if (c == 'S') cs++;
        if (c == 'C') cc++;
    }
    int nb, ns, nc, pb, ps, pc;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;
    auto f = [&](ll x) {
        return max((ll)0, cb * x - nb) * pb + max((ll)0, cs * x - ns) * ps + max((ll)0, cc * x - nc) * pc;
    };

    ll l = 0;
    ll h = 1e13;
    while (h - l > 1) {
        ll mid = l + (h - l) / 2;
        if (f(mid) <= r) {
            l = mid;
        } else {
            h = mid;
        }
    }

    cout << l;

    return 0;
}