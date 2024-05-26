#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double n, m, a;
    cin >> n >> m >> a;
    long long int k = ceil(n / a);
    long long int q = ceil(m / a);
    cout << k * q;
    return 0;
}