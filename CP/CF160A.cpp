#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int total = 0;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        coins[i] = t;
        total += t;
    }

    sort(coins, coins + n);

    int count = 0;
    int subtotal = 0;

    int i = n - 1;
    do
    {
        count++;
        subtotal += coins[i];
        i--;
    } while (subtotal <= (total - subtotal));

    cout << count;
    return 0;
}