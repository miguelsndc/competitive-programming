#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------

// undirected
// no loops
// single edges
// breadth-first-search
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    list<int> adj[n + 1];
    vector<bool> visited(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int groups = 0;
    while (true) {
        vi kicked;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() == 1) {
                kicked.push_back(i);
            }
        }
        if (kicked.size() > 0) {
            for (int st : kicked) {
                // go to every node conneceted to st and remove st from their list
                // clear st list
                int el = adj[st].front();  // the whole point is that adj[st] has length 1
                for (auto it = adj[el].begin(); it != adj[el].end(); ++it) {
                    if ((*it) == st) {
                        adj[el].erase(it);
                        break;
                    }
                }
                adj[st].clear();
            }
            groups++;
        } else {
            break;
        }
    }

    cout << groups;

    return 0;
}