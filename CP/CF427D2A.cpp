#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int crimes = 0;
    int police = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (t < 0 && police == 0) {
            crimes++;
        } else {
            police += t;
        }
    }

    cout << crimes;
    return 0;
}