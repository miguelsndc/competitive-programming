#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vector<int> capacities(3);
    vector<int> amounts(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> capacities[i] >> amounts[i];
    }

    for (int i = 0; i < 100; i++)
    {
        int b1 = i % 3;
        int b2 = (i + 1) % 3;
        int am = min(amounts[b1], capacities[b2] - amounts[b2]);

        amounts[b1] -= am;
        amounts[b2] += am;
    }

    cout << amounts[0] << '\n'
         << amounts[1] << '\n'
         << amounts[2];

    return 0;
}