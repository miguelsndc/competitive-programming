#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n, m; cin >> n >> m;
    int x = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        sum += s.size();
        if (sum <= m) {
            ++x;
        }
    }
    cout << x << '\n';
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