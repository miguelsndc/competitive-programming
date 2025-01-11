#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define INF 1000000009

void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    int step = a + b + c;

    if (n < step) {
        int sm = 0;
        if (a >= n) sm = 1;
        else if (a + b >= n) sm = 2;
        else if (a + b + c >= n) sm = 3;
        cout << sm << '\n';
        return;
    } 
    
    if (n == step) {
        cout << 3 << '\n';
        return;
    } 
    // take as most full steps as possible
    int k = (n / step), d = step * k;
    // distance left
    int m = n % step;

    // cover distance
    int v[3] = {a, b, c}, idx = 0;
    while(d < n) {
        d += v[(idx++) % 3];
    }

    cout << k * 3 + idx<< '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
         solve();
    }
}