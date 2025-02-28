#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tt; cin >> tt;
	while(tt--) {
	    // perm size
	    int n; cin >> n;
	    vector<int> v(2 * n);
	    for (int i = 0; i < 2 * n; i++) {
	        cin >> v[i];
	    }
	    long long cnt = 0, ans = 0;
	    for (int i = 0; i < 2* n; i++) {
	        if (v[i] <= n) ans += cnt;
	        else cnt++;
	    }
	    cout << ans << '\n';
	}
}
