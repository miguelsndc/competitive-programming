#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, h;
    cin >> n >> h;
    int width = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        width += temp > h ? 2 : 1;
    }
    cout << width;
    return 0;
}