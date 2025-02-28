#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tt; cin >> tt;
	while(tt--) {
	    int n; cin >> n;
	    vector<long long> even, odd;
	    long long sumodd = 0, sumeven = 0;
	    for (int i = 0; i < n; i++) {
	        int x; cin >> x;
	        if (i & 1) {
	            odd.push_back(abs(x));
	            sumodd += abs(x);
	        } else {
	            even.push_back(abs(x));
	            sumeven += abs(x);
	        }
	    }
	    
	    long long currsum = sumeven - sumodd;
	    
	   // 3 2 1 0 1 2 3
	   // +3 -2 +1 -0 + 1 -2 +3 = 4
	   // 3 + 1+ 1+ 3 = 8
	   // 2 + 0 + 2 = 4 8 - 4 = 0
	   
	   long long mineven = *min_element(begin(even), end(even));
	   long long maxodd = *max_element(begin(odd), end(odd));
	   
	   cout << max(currsum, (sumeven - mineven + maxodd - sumodd + maxodd - mineven)) << '\n';
	}
}
