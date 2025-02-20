#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int ans = 0;
    for (int i = 0; i < s1.size(); i++) {
        s1[i] += s1[i] >= 97 ? 0 : 32;
        s2[i] += s2[i] >= 97 ? 0 : 32;

        if (s1[i] < s2[i]) {
            ans = -1;
            break;
        } else if (s1[i] > s2[i]) {
            ans = 1;
            break;
        }
    }

    cout << ans;
    return 0;
}