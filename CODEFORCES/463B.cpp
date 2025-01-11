#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int amount = 0;
    int energy = 0;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        energy += pos - t;
        if (energy < 0)
        {
            amount += -energy;
            energy = 0;
        }
        pos = t;
    }
    cout << amount;

    return 0;
}