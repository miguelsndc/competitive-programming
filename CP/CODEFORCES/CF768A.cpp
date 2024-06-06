#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll stewards[n];
    for (int i = 0; i < n; i++)
    {
        cin >> stewards[i];
    }

    sort(stewards, stewards + n);
    int count = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (stewards[i] > stewards[0] && stewards[i] < stewards[n - 1])
            count++;
    }

    cout << count;

    return 0;
}