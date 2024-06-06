#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // n/f
    // 4 2
    // ---

    int a, b;
    cin >> a >> b;
    int n[a], f[a];
    vector<pair<int, int>> sales(a);
    for (int i = 0; i < a; i++)
    {
        cin >> n[i] >> f[i];
        sales[i] = make_pair(min(2 * n[i], f[i]) - min(n[i], f[i]), i);
    }

    ll max_sum = 0;
    sort(sales.rbegin(), sales.rend());
    for (int i = 0; i < b; i++)
        max_sum += min(2 * n[sales[i].second], f[sales[i].second]);
    for (int i = b; i < a; i++)
    {
        max_sum += min(n[sales[i].second], f[sales[i].second]);
    }
    cout << max_sum;
}