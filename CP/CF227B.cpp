#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int binary_search(int *list, int target, int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (list[middle] == target)
            return middle;
        if (list[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n + 1], num;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        arr[num] = i;
    }

    int m, q;
    cin >> m;
    ll left = 0;
    ll right = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> q;
        left += arr[q];
        right += n - arr[q] + 1;
    }

    cout << left << ' ' << right;
}
