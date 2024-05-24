#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'C' || c == 'M' || c == 'Y')
            {
                cout << "#Color";
                return 0;
            }
        }
    }

    cout << "#Black&White";
    return 0;
}