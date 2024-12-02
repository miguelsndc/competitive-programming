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

bool found = false;
void solve(int n, vi& A, vi& v, int sum, int i) {
    if (found) return;

    if (n == sum) {
        found = true;
        return;
    }

    if (i >= A.size() || n > sum && !found) {
        v.pop_back();
        return;
    } else if (!found) {
        v.push_back(A[i]);
    }

    solve(n + A[i], A, v, sum, i + 1);
    solve(n, A, v, sum, i + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    int c = 1;
    while (tc--) {
        int n, d;
        cin >> n;
        vi A(n);
        vi v;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        cin >> d;

        solve(0, A, v, d, 0);

        if (found) {
            if (v.size() > 0) {
                cout << "Caso " << c << ": " << "{";
                for (int i = 0; i < v.size() - 1; i++) {
                    cout << v[i] << ",";
                }
                cout << v[v.size() - 1] << "}\n";
            } else {
                cout << "Caso " << c << ": " << "{}" << '\n';
            }
        } else {
            cout << "Caso " << c << ": " << -1 << '\n';
        }
        c++;
        found = false;
    }
    return 0;
}