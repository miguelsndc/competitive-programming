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

typedef tuple<int, int, int> edge;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> g(5, vi(5));

    g[0][1] = 1;
    g[0][2] = 1;
    g[1][3] = 2;
    g[2][3] = 1;
    g[2][4] = 5;
    g[3][4] = 1;

    vi distances(5, INT32_MAX);
    vb visited(5);

    priority_queue<edge, vector<edge>, greater<edge>> pq;  // (weight, from, to)
    distances[0] = 0;
    pq.push({0, 0, 0});
    for (int i = 0; i < 5; i++) {
        int from, to;
        do {
            tie(ignore, from, to) = pq.top();
            pq.pop();
        } while (visited[to]);
        visited[to] = true;
        for (int w = 0; w < 5; w++) {
            if (g[to][w] > 0 && !visited[w]) {
                int new_dist = distances[to] + g[to][w];
                if (new_dist < distances[w]) {
                    distances[w] = new_dist;
                    pq.push({new_dist, to, w});
                }
            }
        }
    }

    return 0;
}