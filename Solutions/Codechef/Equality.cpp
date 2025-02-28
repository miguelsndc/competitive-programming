#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	// your code goes here
    /*
        might want to sort the numbers and start from the smallest
    */
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<ll> v(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        sum /= n - 1;
        for (int i = 0; i < n; i++) {
            cout << sum - v[i] << ' ';
        }
        cout << '\n';
    }
}
