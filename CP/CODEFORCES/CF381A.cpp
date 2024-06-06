#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int *game = new int [n];

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        game[i] = t;
    }

    int l = 0;
    int r = n - 1;

    int s = 0;
    int d = 0;

    int s_played = false;

    while (l <= r) {
        int points = 0;

        if(game[l] >= game[r]) {
            points = game[l];
            l++;
        } else {
            points = game[r];
            r--;
        }

        if (!s_played) {
            s += points;
            s_played = true;
        } else {
            d += points;
            s_played = false;
        }
    }

    cout << s << ' ' << d;

    delete[] game;
    return 0;
}