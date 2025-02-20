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

// 14 8
// 7 8
// 7 4
// 7 2
// 7 0
// 15 20
// 15 10
// 15 5
// 5 5

int solve(int a, int b) {
    if (a == b) return 0;
    queue<pii> qa, qb;
    map<int, int> ma, mb;
    qa.push({a, 0});
    qb.push({b, 0});
    int ans = -1;
    while (!qa.empty() || !qb.empty()) {
        if (!qa.empty()) {
            int n = qa.front().f;
            int level = qa.front().s;
            qa.pop();
            ma[n] = level;
            if (mb[n] != 0) {
                ans = level + mb[n];
                break;
            }
            if (n % 2 == 0) qa.push({n / 2, level + 1});
            if (n % 3 == 0) qa.push({n / 3, level + 1});
            if (n % 5 == 0) qa.push({n / 5, level + 1});
        }
        if (!qb.empty()) {
            int n = qb.front().f;
            int level = qb.front().s;
            mb[n] = level;
            if (ma[n] != 0) {
                ans = level + ma[n];
                break;
            }
            qb.pop();
            if (n % 2 == 0) qb.push({n / 2, level + 1});
            if (n % 3 == 0) qb.push({n / 3, level + 1});
            if (n % 5 == 0) qb.push({n / 5, level + 1});
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);

    return 0;
}