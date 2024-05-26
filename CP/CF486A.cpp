#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n;
    cin >> n;
    long long int ans = (n / 2) * ((n / 2) + 1) - ((n + 1) / 2) * ((n + 1) / 2);
    cout << ans;
    return 0;
}