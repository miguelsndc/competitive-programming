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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    vll count(x + 1);

    count[0] = 1;
    int m = 1e9 + 7;
    for (int a = 1; a <= x; a++) {
        for (auto c : {1, 2, 3, 4, 5, 6}) {
            if (a - c >= 0) {
                count[a] += count[a - c];
                count[a] %= m;
            } else {
                break;
            }
        }
    }
    cout << count[x];

    return 0;
}