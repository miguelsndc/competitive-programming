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

// we need to simulate a behaviour of an array of stacks
// passing stuff from the top of one to the top of the others
// we need inner access so let's use a vector instead of an actual stack
// baskets are numbered increasingly so let's use a matrix
// Simulation problem

void solve(int n, int m, int q) {
    int a, x;
    char query;
    vector<vi> tb(m);
    for (int i = 0; i < n; i++) {
        tb[0].push_back(i);
    }
    for (int j = 0; j < q; j++) {
        cin >> query >> a >> x;
        if (query == 's' && tb[a].size() > 0) {
            tb[x].push_back(tb[a].back());
            tb[a].pop_back();
        } else if (query == 'c') {
            if (tb[a].size() > x)
                cout << tb[a][x] << '\n';
            else
                cout << -1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    solve(n, m, q);
    return 0;
}