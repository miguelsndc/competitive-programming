#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int seq[n];
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    sort(seq, seq + n);

    int minutes = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (minutes + seq[i] <= x) {
            minutes += seq[i];
            count++;
        } else {
            break;
        }
    }

    cout << count;

    return 0;
}