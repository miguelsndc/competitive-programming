#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int d = 0;
    char *s = new char[n + 1];
    for (int i = 0; i < n; i++)
    {
        s[i] = (d % min(k, 26)) + 97;
        d++;
    }

    s[n] = '\0';

    cout << s;

    return 0;
}