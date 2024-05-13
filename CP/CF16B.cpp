#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool cmpfunc(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second <= b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> bag(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        bag[i] = make_pair(a, b);
    }

    sort(bag.begin(), bag.end(), cmpfunc);

    ll sum = 0;
    ll up = n;
    for (int i = m - 1; i >= max(m - 1 - up, (ll)0); i--)
    {
        sum += min(bag[i].first, n) * bag[i].second;
        n -= bag[i].first;
        if (n <= 0)
            break;
    }
    cout << sum;

    return 0;
}