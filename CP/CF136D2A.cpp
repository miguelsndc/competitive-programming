#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int l[n];

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        l[t - 1] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << l[i] << ' ';
    }

    return 0;
}