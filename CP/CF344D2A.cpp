#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore(); // shitty fix

    int groups = 0;
    int a = -1, b = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if(a != b) {
           groups++;
        }
        b = a;
    }

    cout << groups;

    return 0;
}