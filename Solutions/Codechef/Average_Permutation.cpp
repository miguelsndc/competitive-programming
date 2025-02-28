#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt; cin >> tt;
	while(tt--) {
	    int n; cin >> n;
	    deque<int> ans;
	    for (int i = 1; i <= n; i++) {
	        if (i % 2 == 0) {
	            ans.push_back(i);
	        } else {
	            ans.push_front(i);
	        }
	    }
	    for (int c: ans) {
	        cout << c << ' ';
	    }
	    cout << '\n';
	}
}
