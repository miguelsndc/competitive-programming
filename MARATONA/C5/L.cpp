#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int f(int m, int n, vector<int> &v, int k) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        int mx = -1;
        mx = max(m, v[i] - m);
        while(mx > 5) {

        }
    }

    return x <= k;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int mx = -1;
    int mn = INT32_MAX;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(v[i], mx);
        mn = min(v[i], mn);
    }

    int l = 1, r = mx;
    while(r - l > 1) {
        int m = l + (r - l) / 2;
        if (f(m, n, v, k)) {
            r = m;
        } else {
            r = m;
        }
    }

    cout << l << ' ' << r;
}