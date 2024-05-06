#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;

    vector<string> lines(m);
    for (int i = 0; i < m; i++)
    {
        cin >> lines[i];
    }

    for (int i = 0; i < m * k; i++)
    {
        for (int j = 0; j < k * n; j++)
        {
            cout << lines[i / k][j / k];
        }
        cout << '\n';
    }

    return 0;
}