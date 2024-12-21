#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> g[n];
    for (int i = 0; i < m; i++)  {
        int a, b; cin >> a >> b; --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int currcomp = 0;
    vector<int> components(n, -1);
    vector<int> visited(n);
    int mincomp = 0, minsize = INF;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        components[i] = currcomp;
        queue<int> q; 
        q.push(i);
        int size = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbour: g[node]) {
                if (!visited[neighbour]) {
                    size++;
                    visited[neighbour] = true;
                    components[neighbour] = currcomp;
                }
            }
        }
        if (size > minsize) {
            minsize = size;
            mincomp = currcomp;
        }
        currcomp++;
    }
    for (int i = 0; i < n; i++) {
        components[i] = (components[i] != mincomp);
    }

    for (int i = 0; i < n; i++) {
        cout << components[i] << ' ';
    }
}