#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

string solve() {
    string n; cin >> n;
    ll sum = 0;
    int twos = 0, threes = 0;
    for (int i = 0; i < n.size(); i++) {
        int k = n[i] - '0';
        if (k == 2) twos++;
        else if (k == 3) threes++;
        sum += k;
    }

    bool can = false;
    for (int i = 0; i <= twos; i++) {
        for (int j = 0; j <= threes; j++) {
            ll result = sum + 6 * j + 2 * i;
            if ((result) % 9 == 0) {
                can = true;
                return "YES";
            }
        }
    }

    return "NO";
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
         cout << solve() << '\n';
    }
}