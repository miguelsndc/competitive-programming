#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;

    if (k == n && (n % 2 == 0))
    {
        cout << n;
        return 0;
    }

    if (k == 1)
    {
        cout << 1;
        return 0;
    }

    if (n % 2 == 0 && k > (n / 2))
    {
        k = k % (n / 2);
        cout << 2 * k;
    }
    else if (n % 2 != 0 && k > (n + 1) / 2)
    {
        k = k % ((n + 1) / 2);
        cout << 2 * k;
    }
    else
    {
        cout << (2 * k) - 1;
    }
}