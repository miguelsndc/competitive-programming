#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

int max_depth = 0, reached = false;
bool dfs(int depth, int i, vector<int>&jumps, vector<int>*g, vector<int> &steps, vector<int>& visited) {
    int n = jumps.size() - 1;

    if (i == n) return true;
    
    if(i < 0 || i > n) return false;

    visited[i] = true;
    max_depth = max(max_depth, depth);
    for (int neighbour: g[i]) {
        if (!visited[neighbour] || neighbour == n) {
            reached = dfs(depth + 1, i + jumps[neighbour], jumps, g, steps, visited);
            if (!reached) {
                steps[i] = max(steps[i], -1);
            } else if(steps[i] != -1){
                steps[i] = min(max_depth - depth + 1, steps[i]);
            } else {
                steps[i] = max(max_depth - depth + 1, steps[i]);
            }
            reached = dfs(max_depth - depth + 1, i - jumps[neighbour], jumps, g, steps, visited);
            if (!reached) {
                steps[i] = max(steps[i], -1);
            } else if(steps[i] != -1){
                steps[i] = min(max_depth - depth + 1, steps[i]);
            } else {
                steps[i] = max(max_depth - depth + 1, steps[i]);
            }
        }
    }

    if (!reached) {
        steps[i] = max(steps[i], -1);
    } else {
        steps[i] = min(max_depth - depth + 1, steps[i]);
    }

    return reached;
}

int main() 
{
    // freopen("jumping.in", "r", stdin);
    // freopen("jumping.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> jumps(n);
        for (int i = 0; i < n; i++) {
            cin >> jumps[i];
        }
        vector<int> g[n];
        for (int i = 0; i < n; i++) {
            int jump_forward = i + jumps[i];
            int jump_back = i - jumps[i];

            if (jump_back >= 0) {
                g[i].push_back(jump_back);
            }
            if (jump_forward < n) {
                g[i].push_back(jump_forward);
            }
        }

        vector<int> steps(n, -1);
        vector<int> visited(n);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(0, i, jumps, g, steps, visited);
            max_depth = 0;
            reached = false;
        }

        steps[n - 1] = 0;

        for (int c: steps) {
            cout << c << '\n';
        }
    }
}