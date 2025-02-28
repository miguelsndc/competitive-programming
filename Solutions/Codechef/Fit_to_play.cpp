#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int mn = v[0], diff = 0;
        for (int c: v) {
            mn = min(mn, c);
            if (c - mn > diff) {
                diff = c - mn;
            }
        }
        if (diff == 0) {
            cout << "UNFIT\n";
        } else {
            cout << diff << '\n';
        }
    }
}
