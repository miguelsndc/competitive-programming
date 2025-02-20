#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    cin >> n >> a;
    int cities[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cities[i];
    }

    int left = a - 1;
    int right = a - 1;
    int limak = a - 1;
    int count = 0;
    // 0 0 0 1 0

    while (left >= 0 || right <= n - 1)
    {
        if (left == right && cities[left] && cities[right])
            count++;
        else if (left >= 0 && right <= n - 1 && cities[left] && cities[right])
            count += 2;
        else if (left < 0 && cities[right])
            count++;
        else if (right > n - 1 && cities[left])
            count++;

        left--;
        right++;
    }

    cout << count;

    return 0;
}