#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[i] = b[i] = t;
    }

    sort(b.begin(), b.end());

    if (a.size() == 1) {
        cout << "yes" << '\n'
             << 1 << ' ' << 1;
        return 0;
    }

    int i = 0;
    int j = n - 1;
    while (i < n - 1 && a[i] == b[i]) {
        i++;
    }
    while (j > 0 && a[j] == b[j]) {
        j--;
    }

    if (j == 0 && i == n - 1) {
        cout << "yes" << '\n';
        cout << 1 << ' ' << 1;
        return 0;
    }
    int l = i;
    int r = j;
    while (i < r && j > l && a[i] == b[j]) {
        i++, j--;
    }
    if (l == j && i == r) {
        cout << "yes" << '\n';
        cout << j + 1 << ' ' << i + 1 << "\n";
    } else {
        cout << "no";
    }

    return 0;
}