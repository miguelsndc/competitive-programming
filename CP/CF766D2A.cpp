#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a;
    string b;

    cin >> a >> b;

    if (a == b)
    {
        cout << -1;
    }
    else
    {
        cout << max(a.size(), b.size());
    }
    return 0;
}