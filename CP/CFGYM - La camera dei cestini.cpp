#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> mt[m];
    for (int i = 0; i < n; i++)
        mt[0].push_back(i);

    for (int j = 0; j < q; j++) {
        char t;
        unsigned int a, b;
        cin >> t;
        cin >> a >> b;

        if (t == 's') {
            int top = mt[a].back();
            mt[a].pop_back();
            mt[b].push_back(top);
        } else {
            if (b < mt[a].size()) {
                cout << mt[a][b] << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}