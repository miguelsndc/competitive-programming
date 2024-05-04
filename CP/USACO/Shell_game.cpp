#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> shell_at_pos(3);
    for (int i = 0; i < 3; i++)
    {
        shell_at_pos[i] = i;
    }

    vector<int> counter(3);
    for (int i = 0; i < n; i++)
    {
        int a, b, g;
        cin >> a >> b >> g;

        a--, b--, g--;

        swap(shell_at_pos[a], shell_at_pos[b]);
        counter[shell_at_pos[g]]++;
    }

    cout << max({counter[0], counter[1], counter[2]});
    return 0;
}