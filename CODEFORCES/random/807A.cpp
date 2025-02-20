#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> bf(n), af(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bf[i] >> af[i];
        if (bf[i] != af[i])
        {
            cout << "rated";
            return 0;
        }
    }

    sort(af.rbegin(), af.rend());

    for (int i = 0; i < n; i++)
    {
        if (bf[i] != af[i])
        {
            cout << "unrated";
            return 0;
        }
    }

    cout << "maybe";
    return 0;
}