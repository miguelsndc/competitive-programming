#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// -----------
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int i = 1;
    while (cin >> s && s != "*") {
        if (s == "Hajj") {
            cout << "Case " << i << ": " << "Hajj-e-Akbar" << '\n';
        } else {
            cout << "Case " << i << ": " << "Hajj-e-Asghar" << '\n';
        }
        i++;
    }

    return 0;
}