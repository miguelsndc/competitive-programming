#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    if (n == 1 && t == 10)
    {
        cout << -1;
        return 0;
    }

    string ans;
    for (int i = 0; i < n; i++)
        ans.push_back(to_string(t)[0]);

    if (t == 10)
        ans[n - 1] = '0';

    for (int i = 0; i < n; i++)
        cout << ans[i];

    return 0;
}