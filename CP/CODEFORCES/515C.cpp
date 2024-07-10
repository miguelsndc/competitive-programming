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

// no fucking clue
// try some bullshit

// 1 2 3 4
// 1! * 2! * 3! * 4!
// 4 * 3! * 3! *2!
// 3!*3!*2!*2!*2!

void solve() {}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;
    string digits;
    cin >> digits;
    map<char, string> rep{
        {'0', ""},
        {'1', ""},
        {'2', "2"},
        {'3', "3"},
        {'4', "322"},
        {'5', "5"},
        {'6', "53"},
        {'7', "7"},
        {'8', "7222"},
        {'9', "7332"},
    };

    string ans;
    for (auto ch : digits) {
        ans += rep[ch];
    }

    sort(ans.rbegin(), ans.rend());
    cout << ans;

    return 0;
}