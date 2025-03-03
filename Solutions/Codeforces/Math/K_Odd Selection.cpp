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
        int n,x;cin>>n>>x;
        vi a(n);rep(i,0,n)cin>>a[i];
        int odd = 0, even = 0;
        rep(i,0,n){
            if(a[i] & 1)odd++;
            else even++;
        }
        bool can = false;
        for (int i = 1; i <= odd; i += 2) {
            for (int j = 0; j<= even; j++) {
                if (i + j == x) {
                    can = true; 
                }
            }
        }
        cout << (can ? "Yes\n" : "No\n");
    }
}