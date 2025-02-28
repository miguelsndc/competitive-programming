#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tt; cin >> tt;
	while(tt--) {
	    int n; cin >> n;
	    vector<int> ans(1001);
	    vector<pair<int, int>> g(n);
	    for (int i = 0; i < n; i++) {
	        cin >> g[i].first;
	    }
	    for (int i = 0; i < n; i++) {
	        cin >> g[i].second;
	    }
	    for (const auto &[s, e]: g) {
	        ans[s]++; ans[e]--;
	    }
	    int mx = 0, ps = 0;
	    for (int c: ans) {
	        ps += c;
	        mx = max(mx, ps);
	    }
	    cout << mx << '\n';
	}
}
