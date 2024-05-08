#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int friends[n];
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        friends[i] = --t;
    }
    int distribution[n];
    for (int i = 0; i < n; i++)
    {
        distribution[friends[i]] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << distribution[i] << ' ';
    }

    return 0;
}