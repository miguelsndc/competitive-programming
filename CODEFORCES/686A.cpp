#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, x;
    cin >> n >> x;

    ll total = x;
    ll sad_kids = 0;
    for (int i = 0; i < n; i++)
    {
        char sign;
        ll d;
        cin >> sign >> d;

        if (sign == 43) // +
        {
            total += d;
        }
        else if (sign == 45 && d > total) // 45 = '-'
        {
            ++sad_kids;
        }
        else
        {
            total -= d;
        }
    }

    cout << total << ' ' << sad_kids;

    return 0;
}