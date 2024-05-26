#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll x = 1;
    int power = 1378 % 10;
    int k = log2(n);
    for (int i = 0; i <= k; i++)
    {
        int a = (n >> i) & 1;
        if (a == 1)
            x = (x * power) % 10;
        power = (power * power) % 10;
    }
    cout << x % 10 << '\n';

    return 0;
}