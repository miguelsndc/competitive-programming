#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            v1.push_back(i);
        }
        else if (t == 2)
        {
            v2.push_back(i);
        }
        else
        {
            v3.push_back(i);
        }
    }

    int no_teams = min(v1.size(), min(v2.size(), v3.size()));

    cout << no_teams << '\n';

    for (int i = 0; i < no_teams; i++)
    {
        cout << v1[i] << ' ' << v2[i] << ' ' << v3[i] << '\n';
    }

    return 0;
}