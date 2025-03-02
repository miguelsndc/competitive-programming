#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define rep(var, k, n) for (int var = k; var < n; var++)
#define repi(var, k, n) for (int var = k; var <= n; var++)
#define se second
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n;cin>>n;
        vi v(n);rep(i,0,n)cin>>v[i]; 
        ll cnt=0;
        // if msb of two numbers are equal than & always greater than xor
        map<int,int> msb;
        rep(i, 0, n) {
            int k = 32 - __builtin_clz(v[i]);
            if (msb[k] > 0) {
                cnt += msb[k];
            }
            msb[k]++;
        }
        cout << cnt << '\n';
    }
}