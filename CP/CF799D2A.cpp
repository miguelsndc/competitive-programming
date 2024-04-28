#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int aux = 0;
    int aux_time = 0;
    int ov = 0;
    int ov_time = 0;
    while (aux < n && ov < n)
    {
        ov_time += t;
        ov += ov_time > d ? 2 * k : k;

        aux_time += t;
        aux += k;
    }

    if (ov_time <= aux_time && (ov >= n && aux < n))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}