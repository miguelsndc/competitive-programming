#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tt; cin >> tt;
    while(tt--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int a = *min_element(begin(v), end(v));
        int b = *max_element(begin(v), end(v));
        if (a + b <= k || n == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
