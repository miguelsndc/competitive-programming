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

    int n, k;
    cin >> n >> k;
    vll h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vll F(n + 1, INT32_MAX);
    F[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i + j <= n) {
                F[i + j] = min(F[i + j], F[i] + abs(h[i] - h[i + j]));
            }
        }
    }
    cout << F[n];
    return 0;
}