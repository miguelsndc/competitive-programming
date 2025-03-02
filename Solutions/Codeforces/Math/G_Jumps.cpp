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
        int x; cin>>x;
        int s = 0;
        while(s * (s + 1) < 2 * x) {
            s++;
        }
        if (s * (s+1)/2 ==x+1) {
            s++;
        }
        cout << s << '\n';
    }
}