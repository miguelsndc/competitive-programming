#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------

// (3, 2)
// . . .
// . . . (2, 3)
// . x .
// (a - 1)M + (b - 1
// 2 * 3 + 2- 1/
// 7
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, t, a, b;
    cin >> n >> m >> k >> t;
    vii waste(k);
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        waste[i] = make_pair(a, b);
    }
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        int no_cells = (a - 1) * m + b - 1;  // no of cells before (a,b)
        int no_waste_cells = 0;
        int is_waste = false;
        for (int j = 0; j < k; j++) {
            if (waste[j].first < a) {
                no_waste_cells++;
            } else if (waste[j].first == a && waste[j].second < b) {
                no_waste_cells++;
            } else if (waste[j].first == a && waste[j].second == b) {
                is_waste = true;
            }
        }

        if (is_waste) {
            cout << "Waste\n";
            continue;
        }

        int pos = (no_cells - no_waste_cells) % 3;
        if (pos == 0) {
            cout << "Carrots\n";
        } else if (pos == 1) {
            cout << "Kiwis\n";
        } else {
            cout << "Grapes\n";
        }
    }
}