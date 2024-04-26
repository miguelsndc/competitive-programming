#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int *wires = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> wires[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x;

        if (x != 0) {
            wires[x - 1] += y - 1;
        }

        if (x != n - 1) {
            wires[x +  1] += wires[x] - y;
        }

        wires[x] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << wires[i] << '\n';
    }

    return 0;
}