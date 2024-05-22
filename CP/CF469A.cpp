#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int levels[n + 1];
    memset(levels, 0, (n + 1) * sizeof(int));

    int p;
    cin >> p;
    int t;
    for (int i = 0; i < p; i++)
    {
        cin >> t;
        levels[t]++;
    }

    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> t;
        levels[t]++;
    }

    for (int i = 1; i < (n + 1); i++)
    {
        if (levels[i] == 0)
        {
            cout << "Oh, my keyboard!";
            return 0;
        }
    }

    cout << "I become the guy.";

    return 0;
}