#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int l, r;
    cin >> l >> r;

    if (l % 2 != 0)
        l++;

    if (r - l < 2)
    {
        cout << -1;
        return 0;
    }
    cout << l << ' ' << l + 1 << ' ' << l + 2;
    return 0;
}
