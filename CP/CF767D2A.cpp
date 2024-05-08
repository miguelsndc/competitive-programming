#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int exist[n + 1];
    memset(exist, false, sizeof(exist));
    int next = n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        exist[t] = true;

        if (t == next)
        {
            while (exist[t])
            {
                cout << t << ' ';
                t--;
                next--;
            }
        }
        cout << '\n';
    };

    return 0;
}