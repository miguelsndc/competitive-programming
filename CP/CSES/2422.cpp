#include <iostream>
typedef long long ll;
using namespace std;
ll n;
bool F(ll k) {
    ll s = 0;
    for (int x = 1; x <= n; x++) s += min(n, k / x);
    return s < n * n / 2 + 1;
}
int main() {
    cin >> n;
    ll l = 1, r = n * n;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (F(mid))
            l = mid;
        else
            r = mid;
    }
    cout << r << "\n";
}