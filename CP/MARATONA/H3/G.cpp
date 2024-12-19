#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

int main() 
{
    freopen("jumping.in", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> g[n];
        vector<int> seq(n);
        for (int i = 0; i < n; i++) cin >> seq[i];

        for (int i = 0; i < n; i++) {
            if(i + seq[i] < n) {
                g[i].push_back(i + seq[i]);
                g[i + seq[i]].push_back(i);
            } 
            if (i - seq[i] >= 0) {
                g[i].push_back(i - seq[i]);
                g[i - seq[i]].push_back(i);
            }
        }

        vector <int> dist(n, -1);
        dist[n - 1] = 0;
        queue<int> q;
        q.push(n - 1);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbour: g[node]) {
                if(dist[neighbour] == -1) {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << dist[i] << '\n';
        }
    }
}