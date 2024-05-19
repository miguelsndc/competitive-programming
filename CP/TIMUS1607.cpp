#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int petr, petr_raise, driver, driver_dec;
    cin >> petr >> petr_raise >> driver >> driver_dec;
    while (petr < driver) {
        petr = min(petr + petr_raise, driver);
        driver = max(driver - driver_dec, petr);
    }
    cout << max(petr, driver);
    return 0;
}
