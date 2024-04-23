#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    int u = 0;
    int l = 0;

    for (char &c: s) {
        if (c <= 90) {
            u++;
        } else {
            l++;
        }
    }


    for (char &c: s) {
        if ((u > l) && c >= 97) {
            c -= 32;
        } else if ((u <= l) && c <= 90) {
            c += 32;
        }
    }

    cout << s;
    return 0;
}