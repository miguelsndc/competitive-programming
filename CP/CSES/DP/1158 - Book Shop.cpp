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
    // classical knapsack
    int n, x;
    cin >> n >> x;
    vi price(n + 1);
    vi pages(n + 1);
    for (int i = 1; i <= n; i++) cin >> price[i];
    for (int i = 1; i <= n; i++) cin >> pages[i];

    int knapsack[n + 1][x + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (i == 0 || j == 0)
                knapsack[i][j] = 0;
            else if (price[i] <= j) {
                knapsack[i][j] = max(knapsack[i - 1][j], pages[i] + knapsack[i - 1][j - price[i]]);
            } else {
                knapsack[i][j] = knapsack[i - 1][j];
            }
        }
    }
    cout << knapsack[n][x];
    return 0;
}