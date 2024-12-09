#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int f(int k, vi& speed, vi& dist) {
    int maxp = -1;
    int minp = INT32_MAX;

    for (int i = 0; i < speed.size(); i++) {
        int s = speed[i] * k + dist[i];
        maxp = max(maxp, s);
        minp = min(minp, s);
    }

    return maxp - minp;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(6) << fixed;
    int n, k; cin >> n >> k;
    vi speed(n);
    vi dist(n); 
    loop(i, 0, n) {
        cin >> speed[i] >> dist[i];
    }

    int l = 0, r = k - 1;
    while(r - l > 2) {
        int m1 = l + ((r - l) / 3);
        int m2 = r - ((r - l) / 3);
        int k1 = f(m1, speed, dist);
        int k2 = f(m2, speed, dist);
        if (k1 <= k2) {
            r = m2;
        }
        else{
            l = m1;
        }
    }

    int m = INT32_MAX;
    for(int i = l; i <= r; i++) {
        m = min(m, f(i, speed, dist));
    }
    cout << (double)m;
}