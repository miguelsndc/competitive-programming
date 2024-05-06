#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    int limit[100], bessie[100];
    int length, pos, lim = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> length >> lim;
        for (int j = pos; j < pos + length; j++)
        {
            limit[j] = lim;
        }
        pos += length;
    }

    pos = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> length >> lim;
        for (int j = pos; j < pos + length; j++)
        {
            bessie[j] = lim;
        }
        pos += length;
    }

    int max_over = 0;
    for (int i = 0; i < 100; i++)
    {
        max_over = max(max_over, bessie[i] - limit[i]);
    }

    cout << max_over;

    return 0;
}