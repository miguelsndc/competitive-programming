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
    int n;
    cin >> n;

    // if a + b <= c then c_i will be a + b
    // max possible is (n - 1) + (n - 1) = 2n - 2 > n
    // 0 1 2 3 4
    // 0 1 2 3 4
    // 0 2 4 1 3
    // n = 2
    // 0 1
    // 0 1
    // 0 0 fail
    // n = 3
    // 0 1 2
    // 0 1 2
    // 0 2 1 <- ok
    // n = 1
    // 0
    // 0
    // 0 <- ok actually
    // for now n = 2 fails
    // conjecture: fails if n even
    // n = 4
    // 0 1 2 3
    // 0 1 2 3
    // 0 2 0 2 < fails
    // n = 6
    // n = 9

    if (n % 2 == 0) {
        cout << -1;
        return 0;
    }

    vi a(n), b(n), c(n);

    for (int i = 0; i < n; i++) {
        a[i] = b[i] = i;
        c[i] = (a[i] + b[i]) % n;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
    }
    cout << '\n';

    return 0;
}