#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

bool f(int d, vi&v, int c) {
    // d is the minimum distance we trying now // try to fit all cows

    int n = v.size(), k = 0;
    int p = 0;
    for(int i = 1; i < n; i++) {
        if (v[i] - v[p] >= d) {
            k++;
        } else {
            p = i;
        }
    }

    return k >= c;
}      

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, c; cin >> n >> c;
        vi v(n); loop(i, 0, n) cin >> v[i];
        sort(begin(v), end(v));
        int l = 0, r = v[n - 1] - v[0];

        while(r - l > 1) {
            int m = l + (r - l) / 2;
            if (f(m, v, c)) {
                l = m;
            } else {
                r = m;
            }
        }

        cout << r;
    }
}