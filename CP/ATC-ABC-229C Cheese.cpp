#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> ch(n);
    for (int i = 0; i < n; i++)
        cin >> ch[i].first >> ch[i].second;

    sort(ch.rbegin(), ch.rend());

    ll max_d = 0;
    for (auto &p : ch)
    {
        max_d += p.first * min(w, p.second);
        w -= min(w, p.second);
        if (w == 0)
            break;
    }

    cout << max_d;
    return 0;
}