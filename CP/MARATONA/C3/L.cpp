#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

bool ok(int x, vi & v, int n, int b, int k) {
    int maxs = -1;
    for (int i = 0; i < b; i++) {
        int start = (i == 0 ? 1 : v[i]);
        int end = n;
        bool used = true;
        if (i + x  < b) {
            end = v[i + x-1];
            used = false;
        }
        int seg = end - start;
        maxs = max(maxs, seg);
    }

    return maxs >=k;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k ,b; 
    cin >> n >> k >> b;
    vi v(b); loop(i ,0, b) cin >> v[i];

    // if he fix x signs,  can he get at least k elements in a contiguous blokc?

    sort(begin(v), end(v));
    int ttx = 0;
    for (int c = b; c >= 1; c /= 2) {
        while(!ok(ttx + c, v, n, b, k)) ttx += c;
    }
    cout << ttx;
}