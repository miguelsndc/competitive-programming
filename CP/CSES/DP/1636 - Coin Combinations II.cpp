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
    vll value(x + 1);

    for (int i = 0; i < n; i++) cin >> coins[i];

    value[0] = 1;
    int m = 1e9 + 7;
    for (auto c : coins) {
        for (int u = 0; u <= x; u++) {
            if (u - c >= 0) {
                value[u] += value[u - c];
                value[u] %= m;
            }
        }
    }
    cout << value[x];

    return 0;
}