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
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        char c;
        cin >> n >> m;
        pii top = {-1, 0}, bottom = {0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                if (c == '#') {
                    if (top.f == -1) {
                        top = {i, j};
                    }
                    bottom = {i, j};
                }
            }
        }
        cout << (top.f + bottom.f) / 2 + 1 << ' ' << top.s + 1 << '\n';
    }

    return 0;
}