#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n; cin >> n;
    vector<int> odd, even;
    ll sumodd = 0, sumev = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i % 2) {
            odd.push_back(x); sumodd += x;
        } else {
            even.push_back(x); sumev += x;
        }
    }

    ll u = odd.size();
    ll v = even.size();
    if ((sumodd % u == 0) && (sumev % v == 0) && ((sumodd/u) == (sumev/v))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
         solve();
    }
}