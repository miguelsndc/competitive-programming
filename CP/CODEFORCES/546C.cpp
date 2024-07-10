
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

int dfs(deque<int> &s1, deque<int> &s2, int *depth) {
    if (s1.empty()) {
        return 2;
    } else if (s2.empty()) {
        return 1;
    }

    if (depth[0] > 106) {
        return -1;
    }

    int f1 = s1.front();
    int f2 = s2.front();

    if (f1 > f2) {
        s2.pop_front();
        s1.pop_front();
        s1.push_back(f2);
        s1.push_back(f1);
    } else {
        s2.pop_front();
        s1.pop_front();
        s2.push_back(f1);
        s2.push_back(f2);
    }

    depth[0]++;
    return dfs(s1, s2, depth);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k1, k2, x;
    cin >> n;

    cin >> k1;
    deque<int> s1;
    for (int i = 0; i < k1; i++) {
        cin >> x;
        s1.push_back(x);
    }

    cin >> k2;
    deque<int> s2;
    for (int i = 0; i < k2; i++) {
        cin >> x;
        s2.push_back(x);
    }

    int depth[] = {0};
    int winner = dfs(s1, s2, depth);

    if (winner == -1) {
        cout << -1;
        return 0;
    }

    cout << depth[0] << ' ' << winner;
    return 0;
}