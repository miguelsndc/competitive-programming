#include <bits/stdc++.h>

using namespace std;

void setIO(string name)
{
    if (name.size() > 0)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("pails");
    int x, y, m;
    cin >> x >> y >> m;

    int j = 0;
    int pouring = 0;

    for (int i = 0; i <= m; i++)
    {
        if (x * i > m)
        {
            break;
        }
        for (int j = 0; j <= m; j++)
        {
            int n = x * i + y * j;
            if (n > m)
            {
                break;
            }
            pouring = max(pouring, n);
        }
    }

    cout << pouring;

    return 0;
}