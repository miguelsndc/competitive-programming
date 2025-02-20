#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<int> lanterns(n);
    for (int i = 0; i < n; i++)
        cin >> lanterns[i];
    sort(lanterns.begin(), lanterns.end());
    int maxdist = 2 * max(lanterns[0], l - lanterns[n - 1]);
    for (int i = 0; i < n - 1; i++)
        maxdist = max(maxdist, abs(lanterns[i + 1] - lanterns[i]));
    cout << fixed << setprecision(10) << maxdist / 2.;
    return 0;
}