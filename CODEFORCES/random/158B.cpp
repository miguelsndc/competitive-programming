#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MOD 1000000007
#define ii pair<int, int>

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
    int n; cin >> n;
    int count = 0;
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 4) count++;
        if (x == 3) threes++;
        if (x == 2) twos++;
        if (x == 1) ones++;
    }
    count += (twos / 2);
    int k = min(threes,ones);
    count += k;
    threes -= k;
    ones -= k;
    twos = twos % 2;

    if (twos == 1 && ones >= 2) {
        twos = 0; ones -= 2; count++;
    }

    while(ones >= 4) {
        ones -= 4;
        count++;
    }

    count += threes;

    k = min(twos, ones);

    count += k;

    twos -= k;
    ones -= k;

    count += twos;
    count += (ones >= 1); // ones should form a group since < 4

    cout << count;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
         solve();
    }
}