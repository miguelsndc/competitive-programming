#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, m, L; cin >> n >> m >> L;
        vector<array<int, 3>> hurdles(n);
        vector<array<int, 3>> power_ups(m);
        for (int i = 0; i < n; i++) {
            cin >> hurdles[i][0] >> hurdles[i][1];
            hurdles[i][2] = 0;
        }
        for (int i = 0; i < m; i++) {
            cin >> power_ups[i][0] >> power_ups[i][1];
            power_ups[i][2] = 1;
        }
    }
}