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

// looks like a straightforward CRUD map problem
// use unordered_map because we don't need ordering

void solve(int n) {
    ll am;
    char query;
    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> query >> am;
        if (query == 'a') {
            mp[am]++;
        } else if (query == 't') {
            mp[am]--;
        } else {
            cout << mp[am] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    solve(tc);
    return 0;
}