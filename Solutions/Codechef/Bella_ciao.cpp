#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll apsum(ll a, ll d, ll n) {
    return (n * (2*a + (n - 1)*d))/2;
}

ll nth(ll a, ll d, ll n) {
    return a + (n - 1) * d;
}

int main() {
    // your code goes here
    int tt; cin >> tt;
    while(tt--) {
        long long D, d, P, Q; cin >> D >> d >> P >> Q;
        ll rem = D % d; // remaining
        ll N = D/d; // groups of d
        // value for groups of d begin apsum * d
        ll sum = d * apsum(P, Q, N);
        // remainder group times the nth progression number after the last is the rest
        sum += rem * nth(P, Q, N + 1);
        cout << sum << '\n';
    }
}