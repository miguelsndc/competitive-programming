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

// find out if it's sorted
// go over each coin and keep track of the max seem so far
// if the current is greater than max than max - curr coins are needed to fill the gap
// sum all costs and add 1
ll solve() {
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll max_no = 0, mx = 0, curr = 0;

    for (ll el : a) {
        max_no = max(el, max_no);
        ll d = max_no - el;
        curr += d;
        mx = max(mx, d);
    }

    return curr + mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cout << solve() << '\n';
    }
    return 0;
}