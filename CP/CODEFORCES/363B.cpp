#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// -----------

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int h[n + 1];
    memset(h, 0, (n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) cin >> h[i];

    int i = 1, j = 0, sum = 0;
    while (j < k) {
        sum += h[++j];
    }
    int min_sum = INT_MAX;
    int min_i = i;
    while (j <= n) {
        if (sum < min_sum) {
            min_sum = sum;
            min_i = i;
        }
        sum -= h[i++];
        sum += h[++j];
    }
    cout << min_i;
    return 0;
}