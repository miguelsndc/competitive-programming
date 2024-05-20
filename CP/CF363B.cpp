#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int fences[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> fences[i];

    int i = 1;
    int j = 0;
    int sum = 0;
    int min_sum = INT_MAX;
    int min_index = 1;

    while (j < k)
        sum += fences[++j];

    while (j <= n) {
        if (sum <= min_sum) {
            min_sum = sum;
            min_index = i;
        }
        sum -= fences[i++];
        sum += fences[++j];
    }
    cout << min_index;
    return 0;
}