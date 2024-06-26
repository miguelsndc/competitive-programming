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

void setIO(string name) {
    if (name.size() > 0) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("1680");
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    vector<vi> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[--a].push_back(--b);
    }

    vi prev(n, -1);
    vb visited(n, false);
    queue<int> q;
    q.push(0);
    prev[0] = -2;
    while (!q.empty()) {
        int node = q.front();
        cout << node + 1 << '\n';
        visited[node] = true;
        q.pop();
        for (auto edge : g[node]) {
            if (!visited[edge]) {
                prev[edge] = node;
                q.push(edge);
            }
        }
    }

    if (!visited[n - 1]) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    vi path;
    for (int at = n - 1; at != -2; at = prev[at]) {
        path.push_back(at);
    }

    reverse(path.begin(), path.end());

    for (auto c : path) {
        cout << c + 1 spe;
    }

    return 0;
}