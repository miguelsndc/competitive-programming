#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int zero = 0, one = 0;
        for (char c: s) {
            if (c == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if (min(zero, one) % 2 == 0) {
            cout << "ramos\n";
        } else {
            cout << "zlatan\n";
        }
    }
}
