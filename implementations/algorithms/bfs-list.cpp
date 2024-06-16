#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int N = 10;

void visit(int v) {
    cout << v spe;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vi> adj_list(N);
    vector<bool> visited(N);

    queue<int> q;
    int start = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visit(v);
        for (int u : adj_list[v]) {
            if (!visited[u]) {
                visited[u] = 1;
                q.push(u);
            }
        }
    }

    return 0;
}