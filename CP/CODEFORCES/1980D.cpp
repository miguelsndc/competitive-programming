#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "

bool ok(vi &vec) {
    int g = -1;
    for (int i = 0; i < vec.size() - 1; i++) {
        int current_gcd = __gcd(vec[i], vec[i + 1]);
        if (current_gcd < g) {
            return false;
        }
        g = current_gcd;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vi numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        int max_g = 0;
        int del = -1;
        for (int i = 0; i < n - 1; i++) {
            int curr_gcd = __gcd(numbers[i], numbers[i + 1]);
            if (curr_gcd < max_g) {
                del = i;
                break;
            } else {
                max_g = curr_gcd;
            }
        }

        if (del == -1) {
            cout << "YES\n";
            continue;
        }

        vi v1 = numbers, v2 = numbers, v3 = numbers;
        if (del > 0) v1.erase(v1.begin() + del - 1);
        v2.erase(v2.begin() + del);
        if (del < n - 1) v3.erase(v3.begin() + del + 1);
        if (ok(v1) || ok(v2) || ok(v3)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}