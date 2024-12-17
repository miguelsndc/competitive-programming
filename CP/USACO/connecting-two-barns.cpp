#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // binary search the cost
    int tt; cin >> tt;
    while(tt--) {
        int n, m; cin >> n >> m;
        vector<int> g[n + 1];
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int l = 0, r = ((n - 1) * (n - 1));
        while(l <= r) {
            int m = l + (r - l) / 2;

        }
    }
}