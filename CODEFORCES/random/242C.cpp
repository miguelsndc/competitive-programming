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

int dx[8] = {0, 1, -1, 0, -1, 1, -1, 1};
int dy[8] = {1, 0, 0, -1, -1, 1, 1, -1};

const int N = 1e9 + 1;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("242C.in", "r", stdin);

    pii end;
    pii start;
    map<pii, int> field;
    cin >> start.f >> start.s >> end.f >> end.s;

    int n, r, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) {
            field[{r, j}] = 1;
        }
    }

    queue<pii> q;
    map<pii, int> dist;
    q.push({start.f, start.s});
    dist[{start.f, start.s}] = 0;
    while (!q.empty()) {
        int i = q.front().f, j = q.front().s;
        q.pop();

        field[{i, j}] = 0;
        for (int k = 0; k < 8; k++) {
            int r = i + dx[k];
            int c = j + dy[k];
            if (r < 0 || c < 0 || r >= N || c >= N || field[{r, c}] != 1) continue;

            if (!dist[{r, c}] || dist[{r, c}] > dist[{i, j}] + 1) {
                dist[{r, c}] = dist[{i, j}] + 1;
                q.push({r, c});
            }
        }
    }

    if (dist[{end.f, end.s}] == 0)
        cout << -1;
    else {
        cout << dist[{end.f, end.s}];
    }

    return 0;
}