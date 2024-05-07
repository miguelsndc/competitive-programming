#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }

    ll max_distance = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dx = (x[i] - x[j]);
            int dy = (y[i] - y[j]);
            ll distance = dx * dx + dy * dy;
            max_distance = max(max_distance, distance);
        }
    }

    cout << max_distance;

    return 0;
}