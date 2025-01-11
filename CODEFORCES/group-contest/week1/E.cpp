#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        string res; cin >> res;
        int x; cin >> x;

        int n = res.size();
        string w(n, '1'), b(n, '0');

        for (int i = 0; i < n; i++) {
            if (res[i] == '0') {
                if (i + x < n) w[i + x] = '0';
                if (i - x >= 0) w[i - x] = '0';
            }
        }

        for (int i = 0; i < n; i++) {
            if (i + x < n && w[i + x] == '1') b[i] = '1';
            if (i - x >= 0 && w[i - x] == '1') b[i] = '1';
        }

        if (b == res) {
            cout << w;
        } else {
            cout << -1;
        }
        cout << '\n';
    }
}