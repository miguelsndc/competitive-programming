#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int xs[n];
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }

    for (int i = 0; i < n; i++)
    {
        int maxi = max(abs(xs[0] - xs[i]), abs(xs[i] - xs[n - 1]));
        int mini;
        if (i == 0)
            mini = abs(xs[i] - xs[i + 1]);
        else if (i == n - 1)
            mini = abs(xs[i] - xs[i - 1]);
        else
            mini = min(abs(xs[i] - xs[i - 1]), abs(xs[i] - xs[i + 1]));

        cout << mini << ' ' << maxi << '\n';
    }

    return 0;
}