#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> locations(n);
    for (int i = 0; i < n; i++)
    {
        cin >> locations[i];
    }

    for (int i = 0; i < n; i++)
    {
        int d_left = abs(locations[0] - locations[i]);
        int d_right = abs(locations[n - 1] - locations[i]);
        int max_d = max(d_left, d_right);

        int min_d;
        if (i == 0)
        {
            min_d = abs(locations[i] - locations[i + 1]);
        }
        else if (i == n - 1)
        {
            min_d = abs(locations[i] - locations[i - 1]);
        }
        else
        {
            int right_neighbour = abs(locations[i] - locations[i + 1]);
            int left_neighbour = abs(locations[i] - locations[i - 1]);
            min_d = min(left_neighbour, right_neighbour);
        }

        cout << min_d << ' ' << max_d << '\n';
    }

    return 0;
}