#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int *home = new int [n];
    int *guest = new int [n];

    for (int i = 0; i < n; i++) {
        cin >> home[i] >> guest[i];
    }

    int count= 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (home[i] == guest[j]) {
                count++;
            }
        }
    } 

    cout << count;

    return 0;
}