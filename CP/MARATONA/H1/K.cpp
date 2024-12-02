#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define MOD 1000000007
#define loop(x, s, n) for(int x = s; x < n; x++)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vi y(n);
    loop(i, 0, n) cin >>y[i];
    vi left(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while(s.size() > 0 && y[i] < s.top()) {
            s.pop();
        }
        left[i] = (s.size() > 0) ? s.top() : -1;
        s.push(y[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << left[i] << ' ';
    }
}