#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

bool f(int val, vi v) {
   // can it eat everyone 
}

void solve() {
    int n; cin >> n;
    vi v(n); for(int i=0;i<n;i++) cin>>v[i];
    int mx = *max_element(begin(v), end(v));
    int l = 0, r = mx, ans = mx;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if (f(m, v)) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}