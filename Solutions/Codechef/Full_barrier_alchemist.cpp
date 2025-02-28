#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

void solve() {
    int n, h, y1, y2, l;
    cin >> n >> h>> y1>> y2>> l;
    vector<ii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    
    int cnt = 0;
    for (const auto&[type, barrier]: v) {
        if (type == 1) {
            if (h - y1 > barrier) {
                l--;
            }
        } else {
            if (y2 < barrier) {
                l--;
            }
        }
        if(l <= 0) break;
        cnt++;
    }
    cout << cnt<< '\n';
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}