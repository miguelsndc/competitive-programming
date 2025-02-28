#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        vector<int> even, odd;
        int tomu = 0, max_take = 0, motu = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (i & 1) {
                odd.push_back(x);
                tomu += x;
            } else {
                even.push_back(x);
                motu += x;
            }
        }
        
        sort(rbegin(even), rend(even));
        sort(begin(odd), end(odd));
        
        for (int i = 0; i < min(even.size(), odd.size());i++) {
            if (i < k) {
                max_take += even[i] - odd[i];
            }
        }

        if ((tomu > motu) || ((tomu + max_take) > (motu - max_take))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}