#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int aux[] = {a1,a2,a3,a4};

    cin.ignore();

    string s;
    getline(cin, s);

    int total = 0;
    for (char &i: s) {
        int k = i - '0';
        total += aux[k - 1];
    }

    cout << total;

    return 0;
}