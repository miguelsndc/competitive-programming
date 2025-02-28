#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tt; cin >> tt;
    while(tt--) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(rbegin(v), rend(v));
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            if (v[i]) {
                ans++;
                v[i]--;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (v[i] && v[j]) {
                    ans++; v[i]--, v[j]--;
                }
            }
        }
        cout << ans << '\n';
    }
}
