#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define ii pair<int, int>
#define fi first
#define se second

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

vector<int> a(2000000), b (2000000);
vector<int> ta(2000000), tb(2000000);
oset s;
void solve() {
    int n; cin >> n;

    for (int i = 1; i <= (n); i++) {
        s.insert(i);
    }

    for (int i = 0; i < n / 2; i++) cin >> a[i];
    for (int i = 0; i < n / 2; i++) cin >> b[i];

    for (int i = 0; i < n / 2; i++) {
        auto ita = (s.find_by_order(a[i] - 1));
        int va = *ita;
        s.erase(ita);

        auto itb = (s.find_by_order(b[i] - 1));
        int vb = *itb;
        s.erase(itb);

        ta[i] = (va);
        tb[i] = (vb);
    }

    for (int i = 0; i < n / 2; i++) cout << ta[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n / 2; i++) cout << tb[i] << ' ';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}