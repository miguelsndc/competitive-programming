#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<pii>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define ff first
#define ss second
#define sp << " " <<
#define spe << " "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum, limit;
    cin >> sum >> limit;
    vector<pii> limits;
    for (int i = 1; i <= limit; i++) {
        int lowbit = i & (-i);
        limits.push_back({lowbit, i});
    }

    sort(limits.rbegin(), limits.rend());

    vi ans;
    for (auto p : limits) {
        if (sum - p.ff >= 0) {
            ans.push_back(p.ss);
            sum -= p.ff;
        }
    }

    if (sum == 0) {
        cout << ans.size() << '\n';
        for (auto v : ans) {
            cout << v spe;
        }
    } else {
        cout << -1;
    }

    return 0;
}