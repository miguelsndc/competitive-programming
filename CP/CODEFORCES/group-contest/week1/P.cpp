#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n, temp; cin >> n >> temp;        
    vector<array<int, 3>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    int l = temp, h = temp, time = 0, can = true;
    for (int i = 0; i < n; i++) {
        auto [ctime, lb, hb] = v[i];
        int diff = ctime - time;
        int mint = l - diff, maxt = h + diff;
        if (mint <= hb && maxt >= lb) {
            l = max(lb, mint), h = min(maxt, hb);
        } else if (mint > hb || maxt < lb) {
            can = false; break;
        }
        time = ctime;
    }

    cout << (can ? "YES\n" : "NO\n");
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