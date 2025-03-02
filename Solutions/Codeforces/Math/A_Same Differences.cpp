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
const int maxn = 2e5 + 5;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        /*
        3 5 1 4 6 6
        aj - ai == j - i
        aj - j = ai - i
        bi = bj se b = a- pos
        */

        vi v(n);
        rep(i,0,n)cin>>v[i], v[i] -= i;
        map<ll,ll>mp;
        ll cnt=0;
        rep(i,0,n){
            if (mp[v[i]] > 0) {
                cnt += mp[v[i]];
            }
            mp[v[i]]++;
        }
        cout << cnt << '\n';
    } 
}