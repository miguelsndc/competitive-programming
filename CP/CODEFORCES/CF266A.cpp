#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    short int n;
    cin >> n;

    char p = '\0';
    int c = 0;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;

        if (ch != p) {
            p = ch;
        } else {
            c++;
        }
    }

    cout << c;

    return 0;
}