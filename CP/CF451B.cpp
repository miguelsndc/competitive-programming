#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        a[i] = b[i] = c;
    }

    map<int, int> tb;
    // 1 2 3 4: 0 1 2 3
    // 2 1 3 4: 1 0 2 3

    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        tb[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = tb[b[i]];
    }

    int L = -1;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != i)
        {
            L = i;
            break;
        }
    }

    int R = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (b[i] != i)
        {
            R = i;
            break;
        }
    }

    if (L == -1 || R == -1)
    {
        cout << "yes" << '\n';
        cout << 1 << ' ' << 1;
        return 0;
    }

    reverse(b + L, b + R + 1);
    int ok = true;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != i)
        {
            ok = false;
            break;
        }
    }

    if (ok)
    {
        cout << "yes" << "\n";
        cout << L + 1 << ' ' << R + 1;
    }
    else
    {
        cout << "no";
    }

    return 0;
}