#include <bits/stdc++.h>

using namespace std;

void setIO(string name)
{
    if (name.size() > 0)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("shuffle");

    int n;
    cin >> n;
    vector<int> positions(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        positions[i] = --t;
    }

    vector<int> ids(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ids[i];
    }

    int new_positions[n];
    for (int i = 0; i < 3; i++)
    {
        vector<int> past_order(n);
        for (int j = 0; j < n; j++)
        {
            past_order[j] = ids[positions[j]];
        }
        ids = past_order;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ids[i] << '\n';
    }

    return 0;
}