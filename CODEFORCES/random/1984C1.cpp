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
    // plan 1
    // naively find the max between c + ai and | c + ai |
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vi values(n);
        vll absolute(n + 1);
        vll not_abs(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        ll c = 0;
        ll prev_non_abs = 0;
        for (int i = 0; i < n; i++) {
            absolute[i] = abs(c + values[i]);
            not_abs[i] = (prev_non_abs + values[i]);
            prev_non_abs = not_abs[i];
            c = max(absolute[i], abs(not_abs[i]));
        }

        cout << c << '\n';
    }

    return 0;
}