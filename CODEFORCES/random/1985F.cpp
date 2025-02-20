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
        int h, n;
        cin >> h >> n;
        vi damage(n), cooldowns(n);
        for (int i = 0; i < n; i++) {
            cin >> damage[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> cooldowns[i];
        }
        ll turn = 0;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({1, i});
        }
        while (h > 0) {
            pll i = pq.top();
            h -= damage[i.s];
            pq.pop();
            pq.push({i.f + cooldowns[i.s], i.s});
            turn = i.f;
        }
        cout << turn << '\n';
    }

    return 0;
}