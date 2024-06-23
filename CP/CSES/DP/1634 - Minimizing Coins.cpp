#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vi coins(n);
    vll value(x);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    value[0] = 0;
    for (int i = 1; i <= x; i++) {
        value[i] = INT32_MAX;
        for (auto c : coins) {
            if (i - c >= 0) {  // we can use this coin to construct this sum
                value[i] = min(value[i], value[i - c] + 1);
            }
        }
    }
    if (value[x] == INT32_MAX) {
        cout << -1;
    } else {
        cout << value[x];
    }

    return 0;
}