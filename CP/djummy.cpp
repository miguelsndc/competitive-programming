#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int is_exp_green(int n) {
    ll t = 1;
    return (t << n) <= 1000000;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int left = 0;
    int right = 100;
    // 0 1 2 3 4 5 6 7 9 10
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (is_exp_green(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << right;

    return 0;
}