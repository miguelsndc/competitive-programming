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
    int n;
    cin >> n;
    vi lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    sort(lengths.begin(), lengths.end());
    for (int i = 0; i < n - 2; i++) {
        int a = lengths[i];
        int b = lengths[i + 1];
        int c = lengths[i + 2];
        if ((a + b > c) && (a + c > b) && (b + c > a)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}