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

void solve() {
    int n;
    cin >> n;
    map<string, vector<string>> g;
    map<string, int> distances;
    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[a].push_back(c);
        g[b].push_back(a);
        g[b].push_back(c);
        g[c].push_back(b);
        g[c].push_back(a);
        distances[a] = distances[b] = distances[c] = INT_MAX;
    }

    map<string, bool> visited;
    queue<string> q;
    q.push("Ahmad");
    distances["Ahmad"] = 0;
    while (!q.empty()) {
        string top = q.front();
        q.pop();
        if (visited[top]) continue;
        visited[top] = true;
        for (auto adj : g[top]) {
            if (!visited[adj]) {
                distances[adj] = min(distances[adj], distances[top] + 1);
                q.push(adj);
            }
        }
    }
    vector<pair<string, int>> dist_pair;
    for (auto it : distances) {
        dist_pair.push_back({it.first, it.second});
    }

    sort(dist_pair.begin(), dist_pair.end(), [](const auto &a, const auto &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    cout << dist_pair.size() << '\n';

    for (auto it : dist_pair) {
        cout << it.first << ' ';
        if (it.second == INT_MAX) {
            cout << "undefined";
        } else {
            cout << it.second;
        }
        cout << "\n";
    }
}

void setIO(string name) {
    if (name.size() > 0) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    // setIO("vjg");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}