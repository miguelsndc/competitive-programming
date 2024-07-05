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
    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[a].push_back(c);
        g[b].push_back(a);
        g[b].push_back(c);
        g[c].push_back(b);
        g[c].push_back(a);
    }

    map<string, int> distances;
    map<string, int> visited;
    vector<pair<string, int>> depths;
    queue<string> q;
    q.push("Ahmad");
    distances["Ahmad"] = 0;
    while (!q.empty()) {
        string top = q.front();
        q.pop();
        visited[top] = true;
        for (auto adj : g[top]) {
            if (!visited[adj]) {
                q.push(adj);
                distances[adj] = distances[top] + 1;
            }
        }
    }
}

void setIO(string name) {
    if (name.size() > 0) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("vjg");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}