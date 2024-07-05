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
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vi in_degree(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vi order;
    while (!q.empty()) {
        int at = q.top();
        q.pop();
        order.push_back(at);
        for (auto edge : adj[at]) {
            in_degree[edge]--;
            if (in_degree[edge] == 0) {
                q.push(edge);
            }
        }
    }

    if (order.size() != n) {
        cout << "Sandro fails." << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << order[i];
            if (i != n - 1) {
                cout << " ";
            }
        }
    }

    return 0;
}