#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    set<ll> s; ll ps = 0, ans = 0;
    // insert zero as default sum
    s.insert(ps);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ps += x;
        if (s.find(ps) != s.end()) {
            ans++;   
            s.clear();
            s.insert(0);
            ps = x;
        }
        s.insert(ps);
    }
    cout << ans;
}