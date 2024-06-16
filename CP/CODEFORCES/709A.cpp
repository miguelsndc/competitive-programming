#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, b, d;
    cin >> n >> b >> d;

    int waste = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k <= b)
        {
            waste += k;
        }

        if (waste > d)
        {
            waste = 0;
            count++;
        }
    }

    cout << count;

    return 0;
}