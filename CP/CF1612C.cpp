#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int f(int k) {
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int k, x;
        cin >> k >> x;
        int low = 1;
        int high = 2 * k - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (f(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
    }

    return 0;
}