#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = a[i];
        vb lookup(k + 1);
        while (j > 0) {
            int last = j % 10;
            lookup[last] = true;
            j /= 10;
        }
        if (all_of(lookup.begin(), lookup.end(), [](bool i) { return i; })) {
            count++;
        }
    }
    cout << count;
    return 0;
}