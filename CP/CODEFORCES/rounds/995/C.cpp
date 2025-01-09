#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> list(m); string result(m, '0');

    vector<int> knows(n + 1);
    for (int i = 0; i < m; i++) cin >> list[i];
    for (int i = 0; i < k; i++)  {
        int x; cin >> x;
        knows[x] = 1;
    }

    if (n - k > 1) {
        cout << result << '\n';
        return;
    } else if (n == k) {
        cout << string(m, '1') << '\n';
        return;
    }

    for (int i = 0; i < m; i++) {
        int not_in = list[i];  
        if (knows[not_in] == 0) result[i] = '1';
    }

    cout << result << '\n';
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